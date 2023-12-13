Imports System
Imports System.IO.Ports

Public Class Form1
    Dim vpb_sy, vpb_ly As Integer
    Dim TempL, HumL As Integer
    Dim Temp, Hum, TempResult, HumResult As String

    Private Sub ComboBoxPort_DropDown(sender As Object, e As EventArgs) Handles ComboBoxPort.DropDown
        PanelConnection.Focus()
    End Sub

    Private Sub ComboBoxPort_Click(sender As Object, e As EventArgs) Handles ComboBoxPort.Click
        If LabelStatus.Text = "Status: Connected" Then
            MsgBox("Connection in progress, please Disconnect to change COM Port.", MsgBoxStyle.Critical, "Warning")
            Return
        End If
    End Sub

    Private Sub ComboBaudRate_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBaudRate.SelectedIndexChanged
        PanelConnection.Focus()
    End Sub

    Private Sub ComboBaudRate_DropDown(sender As Object, e As EventArgs) Handles ComboBaudRate.DropDown
        PanelConnection.Focus()
    End Sub

    Private Sub ComboBaudRate_Click(sender As Object, e As EventArgs) Handles ComboBaudRate.Click
        If LabelStatus.Text = "Status: Connected" Then
            MsgBox("Connection in progress, please Disconnect to change Baud Rate.", MsgBoxStyle.Critical, "Warning")
            Return
        End If
    End Sub

    Private Sub ButtonScanPort_Click(sender As Object, e As EventArgs) Handles ButtonScanPort.Click
        PanelConnection.Focus()
        If LabelStatus.Text = "Status: Connected" Then
            MsgBox("Connection in progress, please Disconnect to scan new Port.", MsgBoxStyle.Critical, "Warning")
            Return
        End If
        ComboBoxPort.Items.Clear()
        Dim myPort As Array
        Dim i As String
        myPort = IO.Ports.SerialPort.GetPortNames()
        ComboBoxPort.Items.AddRange(myPort)
        i = ComboBoxPort.Items.Count
        i = i - 1
        Try
            ComboBoxPort.SelectedItem = i
            ButtonConnect.Enabled = True
        Catch ex As Exception
            MsgBox("No port Detected", MsgBoxStyle.Critical, "Warning")
            ComboBoxPort.Text = ""
            ComboBoxPort.Items.Clear()
            Return
        End Try
        ComboBoxPort.DroppedDown = True
    End Sub

    Private Sub ButtonConnect_Click(sender As Object, e As EventArgs) Handles ButtonConnect.Click
        PanelConnection.Focus()
        Try
            SerialPort1.BaudRate = ComboBaudRate.SelectedItem
            SerialPort1.PortName = ComboBoxPort.SelectedItem
            SerialPort1.Open()
            TimerSerial.Start()

            LabelStatus.Text = "Status: Connected"
            ButtonConnect.SendToBack()
            ButtonDisconnect.BringToFront()
            PictureBoxStatusConnection.Visible = True
            PictureBoxStatusConnection.BackColor = Color.Green
        Catch ex As Exception
            MsgBox("Please check the Hardware, COM, Baud Rate and try again.", MsgBoxStyle.Critical, "Connection Failed")
        End Try
    End Sub

    Private Sub ButtonDisconnect_Click(sender As Object, e As EventArgs) Handles ButtonDisconnect.Click
        PanelConnection.Focus()
        TimerSerial.Stop()
        SerialPort1.Close()
        ButtonConnect.BringToFront()
        ButtonDisconnect.SendToBack()
        LabelStatus.Text = "Status: Disconnected"
        PictureBoxStatusConnection.Visible = True
        PictureBoxStatusConnection.BackColor = Color.Red
    End Sub

    Private Sub TimerSerial_Tick(sender As Object, e As EventArgs) Handles TimerSerial.Tick
        Try
            StrSerialIn = SerialPort1.ReadExisting

            Dim TB As New TextBox
            TB.Multiline = True
            TB.Text = StrSerialIn

            If TB.Lines.Count > 0 Then
                If TB.Lines(0) = "Failed to read from DHT sensor!" Then
                    TimerSerial.Stop()
                    SerialPort1.Close()
                    LabelStatus.Text = "Status: Disconnected"
                    ButtonConnect.BringToFront()
                    ButtonDisconnect.SendToBack()
                    PictureBoxStatusConnection.Visible = True
                    PictureBoxStatusConnection.BackColor = Color.Red
                    MsgBox("Failed to read from DHT sensor!, Please check the Hardware and connect again", MsgBoxStyle.Critical, "Connection Failed")
                End If
            End If

            StrSerialInRam = TB.Lines(0).Substring(0, 1)
            If StrSerialInRam = "H" Then
                Hum = TB.Lines(0)
                HumL = Hum.Length
            Else
                Hum = Hum
            End If

            StrSerialInRam = TB.Lines(1).Substring(0, 1)
            If StrSerialInRam = "T" Then
                Temp = TB.Lines(1)
                TempL = Temp.Length
            Else
                Temp = Temp
            End If

            HumResult = Mid(Hum, 2, HumL)
            TempResult = Mid(Temp, 2, TempL)
            Dim humValue As Integer
            Dim tempValue As Integer
            Integer.TryParse(HumResult, humValue)
            Integer.TryParse(TempResult, tempValue)

            CircleProgressbarHumidity.Value = humValue
            VProgressbarTemperature.Value = TempResult
            LabelTemperature.Text = TempResult + " °C"

            Chart1.Series("Humidity      ").Points.AddY(HumResult)
            If Chart1.Series(0).Points.Count = ChartLimit Then
                Chart1.Series(0).Points.RemoveAt(0)
            End If
            Chart2.Series("Temperature").Points.AddY(TempResult)
            If Chart2.Series(0).Points.Count = ChartLimit Then
                Chart2.Series(0).Points.RemoveAt(0)
            End If

            If PictureBoxStatusConnection.Visible = True Then
                PictureBoxStatusConnection.Visible = False
            ElseIf PictureBoxStatusConnection.Visible = False Then
                PictureBoxStatusConnection.Visible = True
            End If

        Catch ex As Exception

            'MessageBox.Show(ex.Message)
            TimerSerial.Stop()
            SerialPort1.Close()
            LabelStatus.Text = "Status: Disconnected"
            ButtonDisconnect.SendToBack()
            ButtonConnect.BringToFront()
            PictureBoxStatusConnection.BackColor = Color.Red
            MsgBox("Please check the Hardware and connect again", MsgBoxStyle.Critical, "Connection Failed")
        End Try
    End Sub

    Private Sub ComboBoxPort_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBoxPort.SelectedIndexChanged
        PanelConnection.Focus()
    End Sub

    Dim TempToProgressBar As Single
    Dim ChartLimit As Integer = 30
    Dim StrSerialIn, StrSerialInRam As String

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Me.CenterToScreen()
        PanelConnection.Focus()
        CircleProgressbarHumidity.Value = 0
        VProgressbarTemperature.Value = 0
        ComboBaudRate.SelectedIndex = 0

        For i = 0 To 30 Step 1
            Chart1.Series("Humidity      ").Points.AddY(0)
            If Chart1.Series(0).Points.Count = ChartLimit Then
                Chart1.Series(0).Points.RemoveAt(0)
            End If

            Chart2.Series("Temperature").Points.AddY(0)
            If Chart2.Series(0).Points.Count = ChartLimit Then
                Chart2.Series(0).Points.RemoveAt(0)
            End If
        Next

        Chart1.ChartAreas(0).AxisY.Maximum = 180
        Chart1.ChartAreas(0).AxisY.Minimum = -20
        Chart1.ChartAreas("ChartArea1").AxisX.LabelStyle.Enabled = False
        Chart2.ChartAreas(0).AxisY.Maximum = 70
        Chart2.ChartAreas(0).AxisY.Minimum = -30
        Chart2.ChartAreas("ChartArea1").AxisX.LabelStyle.Enabled = False
    End Sub
End Class
