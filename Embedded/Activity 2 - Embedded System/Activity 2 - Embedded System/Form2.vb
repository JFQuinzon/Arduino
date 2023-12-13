﻿Public Class Form2
    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Me.CenterToParent()
        BtnCon.Enabled = False
        BtnCon.BringToFront()

        BtnDiscon.Enabled = False
        BtnDiscon.SendToBack()

        CmbBaud.Items.Add("9600")
    End Sub

    Private Sub BtnScanPort_Click(sender As Object, e As EventArgs) Handles BtnScanPort.Click
        CmbScanPort.Items.Clear()
        Dim myPort As Array
        Dim i As Integer
        myPort = IO.Ports.SerialPort.GetPortNames()
        CmbScanPort.Items.AddRange(myPort)
        i = CmbScanPort.Items.Count
        i = i - i
        Try
            CmbScanPort.SelectedIndex = i
        Catch ex As Exception
            Dim result As DialogResult
            result = MessageBox.Show("com port not detected", "Warning!!!", MessageBoxButtons.OK)
            CmbScanPort.Text = ""
            CmbScanPort.Items.Clear()
            Call Form2_Load(Me, e)
        End Try
        BtnCon.Enabled = True
        BtnCon.BringToFront()
        CmbScanPort.DroppedDown = True
    End Sub

    Private Sub BtnCon_Click(sender As Object, e As EventArgs) Handles BtnCon.Click
        Try
            BtnCon.Enabled = False
            BtnCon.SendToBack()

            SerialPort1.BaudRate = CmbBaud.SelectedItem()
            SerialPort1.PortName = CmbScanPort.SelectedItem()
            SerialPort1.Open()
            Timer1.Start()

            BtnDiscon.Enabled = True
            BtnDiscon.BringToFront()
        Catch ex As Exception
            MessageBox.Show("Please select baud rate.")
        End Try

    End Sub

    Private Sub BtnDiscon_Click(sender As Object, e As EventArgs) Handles BtnDiscon.Click
        BtnDiscon.Enabled = False
        BtnDiscon.SendToBack()

        Timer1.Stop()
        SerialPort1.Close()

        BtnCon.Enabled = True
        BtnCon.BringToFront()

    End Sub

    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        Try
            Dim i As Single = SerialPort1.ReadExisting
            Lblpotentiometer.Text = "Potentiometer Value: " + i.ToString
        Catch ex As Exception

        End Try
    End Sub
End Class