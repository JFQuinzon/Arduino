<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.BtnScanPort = New System.Windows.Forms.Button()
        Me.CmbScanPort = New System.Windows.Forms.ComboBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.CmbBaud = New System.Windows.Forms.ComboBox()
        Me.BtnCon = New System.Windows.Forms.Button()
        Me.BtnDiscon = New System.Windows.Forms.Button()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.Lblpotentiometer = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'BtnScanPort
        '
        Me.BtnScanPort.Location = New System.Drawing.Point(12, 12)
        Me.BtnScanPort.Name = "BtnScanPort"
        Me.BtnScanPort.Size = New System.Drawing.Size(199, 44)
        Me.BtnScanPort.TabIndex = 0
        Me.BtnScanPort.Text = "Scan Port"
        Me.BtnScanPort.UseVisualStyleBackColor = True
        '
        'CmbScanPort
        '
        Me.CmbScanPort.FormattingEnabled = True
        Me.CmbScanPort.Location = New System.Drawing.Point(227, 25)
        Me.CmbScanPort.Name = "CmbScanPort"
        Me.CmbScanPort.Size = New System.Drawing.Size(234, 21)
        Me.CmbScanPort.TabIndex = 1
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(467, 28)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(61, 13)
        Me.Label1.TabIndex = 2
        Me.Label1.Text = "Baud Rate:"
        '
        'CmbBaud
        '
        Me.CmbBaud.FormattingEnabled = True
        Me.CmbBaud.Items.AddRange(New Object() {"1200", "2400", "4800", "19200", "38400", "57600", "115200"})
        Me.CmbBaud.Location = New System.Drawing.Point(534, 28)
        Me.CmbBaud.Name = "CmbBaud"
        Me.CmbBaud.Size = New System.Drawing.Size(234, 21)
        Me.CmbBaud.TabIndex = 3
        '
        'BtnCon
        '
        Me.BtnCon.Location = New System.Drawing.Point(12, 62)
        Me.BtnCon.Name = "BtnCon"
        Me.BtnCon.Size = New System.Drawing.Size(199, 48)
        Me.BtnCon.TabIndex = 4
        Me.BtnCon.Text = "Connect"
        Me.BtnCon.UseVisualStyleBackColor = True
        '
        'BtnDiscon
        '
        Me.BtnDiscon.Location = New System.Drawing.Point(12, 62)
        Me.BtnDiscon.Name = "BtnDiscon"
        Me.BtnDiscon.Size = New System.Drawing.Size(199, 48)
        Me.BtnDiscon.TabIndex = 5
        Me.BtnDiscon.Text = "Disconnect"
        Me.BtnDiscon.UseVisualStyleBackColor = True
        '
        'Timer1
        '
        '
        'Lblpotentiometer
        '
        Me.Lblpotentiometer.AutoSize = True
        Me.Lblpotentiometer.Font = New System.Drawing.Font("Microsoft Sans Serif", 36.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Lblpotentiometer.Location = New System.Drawing.Point(113, 139)
        Me.Lblpotentiometer.Name = "Lblpotentiometer"
        Me.Lblpotentiometer.Size = New System.Drawing.Size(566, 55)
        Me.Lblpotentiometer.TabIndex = 6
        Me.Lblpotentiometer.Text = "Potentiometer Value: 000"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(803, 342)
        Me.Controls.Add(Me.Lblpotentiometer)
        Me.Controls.Add(Me.BtnCon)
        Me.Controls.Add(Me.CmbBaud)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.CmbScanPort)
        Me.Controls.Add(Me.BtnScanPort)
        Me.Controls.Add(Me.BtnDiscon)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents BtnScanPort As Button
    Friend WithEvents CmbScanPort As ComboBox
    Friend WithEvents Label1 As Label
    Friend WithEvents CmbBaud As ComboBox
    Friend WithEvents BtnCon As Button
    Friend WithEvents BtnDiscon As Button
    Friend WithEvents SerialPort1 As IO.Ports.SerialPort
    Friend WithEvents Timer1 As Timer
    Friend WithEvents Lblpotentiometer As Label
End Class
