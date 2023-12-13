Imports System.IO.Ports

Public Class Form2

    Dim myPorts As Array
    Dim yellow As Integer
    Private Sub Form2_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Try
            myPorts = IO.Ports.SerialPort.GetPortNames
            CB_Port.Items.AddRange(myPorts)
            CB_Port.SelectedItem = CB_Port.Items(0)

            SerialPort1.BaudRate = (9600)
        Catch ex As Exception

        End Try
    End Sub

    Private Sub SendYellowVal_Click(sender As Object, e As EventArgs) Handles SendYellowVal.Click
        Try
            SerialPort1.Open()
            SerialPort1.WriteLine("255")
            SerialPort1.Close()
        Catch ex As Exception

        End Try
    End Sub

    Private Sub BunifuTrackbar1_ValueChanged(sender As Object, e As EventArgs) Handles BunifuTrackbar1.ValueChanged
        yellow = BunifuTrackbar1.Value
    End Sub

    Private Sub CB_Port_SelectedIndexChanged(sender As Object, e As EventArgs) Handles CB_Port.SelectedIndexChanged
        Try
            SerialPort1.PortName = CB_Port.Text
        Catch ex As Exception

        End Try
    End Sub

    Private Sub SendRedVal_Click(sender As Object, e As EventArgs) Handles SendRedVal.Click
        Try
            SerialPort1.Open()
            SerialPort1.WriteLine("0")
            SerialPort1.Close()
        Catch ex As Exception

        End Try
    End Sub
End Class