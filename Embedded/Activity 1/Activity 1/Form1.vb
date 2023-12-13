Public Class Form1
    Dim myPorts As Array

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Try
            myPorts = IO.Ports.SerialPort.GetPortNames
            CB_Port.Items.AddRange(myPorts)
            CB_Port.SelectedItem = CB_Port.Items(0)

            SerialPort1.BaudRate = (9600)
        Catch ex As Exception

        End Try

    End Sub

    Private Sub CB_Port_SelectedIndexChanged(sender As Object, e As EventArgs) Handles CB_Port.SelectedIndexChanged
        Try
            SerialPort1.PortName = CB_Port.Text
        Catch ex As Exception

        End Try
    End Sub

    Private Sub btnON_Click(sender As Object, e As EventArgs) Handles btnON.Click
        Try
            SerialPort1.Open()
            SerialPort1.WriteLine("on")
            SerialPort1.Close()
        Catch ex As Exception

        End Try
    End Sub

    Private Sub btnOFF_Click(sender As Object, e As EventArgs) Handles btnOFF.Click
        Try
            SerialPort1.Open()
            SerialPort1.WriteLine("off")
            SerialPort1.Close()
        Catch ex As Exception

        End Try

    End Sub
End Class
