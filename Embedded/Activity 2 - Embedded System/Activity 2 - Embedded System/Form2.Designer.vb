<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form2
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form2))
        Dim BorderEdges7 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges()
        Dim StateProperties13 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim StateProperties14 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim BorderEdges8 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges()
        Dim StateProperties15 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim StateProperties16 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim BorderEdges9 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges()
        Dim StateProperties17 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim StateProperties18 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Me.BtnScanPort = New Bunifu.UI.WinForms.BunifuButton.BunifuButton()
        Me.CmbScanPort = New Guna.UI.WinForms.GunaComboBox()
        Me.CmbBaud = New Guna.UI.WinForms.GunaComboBox()
        Me.Lblpotentiometer = New Bunifu.Framework.UI.BunifuCustomLabel()
        Me.BunifuCustomLabel2 = New Bunifu.Framework.UI.BunifuCustomLabel()
        Me.BtnCon = New Bunifu.UI.WinForms.BunifuButton.BunifuButton()
        Me.BtnDiscon = New Bunifu.UI.WinForms.BunifuButton.BunifuButton()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.SuspendLayout()
        '
        'BtnScanPort
        '
        Me.BtnScanPort.AllowToggling = False
        Me.BtnScanPort.AnimationSpeed = 200
        Me.BtnScanPort.AutoGenerateColors = False
        Me.BtnScanPort.BackColor = System.Drawing.Color.Transparent
        Me.BtnScanPort.BackColor1 = System.Drawing.Color.Moccasin
        Me.BtnScanPort.BackgroundImage = CType(resources.GetObject("BtnScanPort.BackgroundImage"), System.Drawing.Image)
        Me.BtnScanPort.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        Me.BtnScanPort.ButtonText = "SCAN PORT"
        Me.BtnScanPort.ButtonTextMarginLeft = 0
        Me.BtnScanPort.ColorContrastOnClick = 45
        Me.BtnScanPort.ColorContrastOnHover = 45
        Me.BtnScanPort.Cursor = System.Windows.Forms.Cursors.Hand
        BorderEdges7.BottomLeft = True
        BorderEdges7.BottomRight = True
        BorderEdges7.TopLeft = True
        BorderEdges7.TopRight = True
        Me.BtnScanPort.CustomizableEdges = BorderEdges7
        Me.BtnScanPort.DialogResult = System.Windows.Forms.DialogResult.None
        Me.BtnScanPort.DisabledBorderColor = System.Drawing.Color.FromArgb(CType(CType(191, Byte), Integer), CType(CType(191, Byte), Integer), CType(CType(191, Byte), Integer))
        Me.BtnScanPort.DisabledFillColor = System.Drawing.Color.FromArgb(CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer))
        Me.BtnScanPort.DisabledForecolor = System.Drawing.Color.FromArgb(CType(CType(168, Byte), Integer), CType(CType(160, Byte), Integer), CType(CType(168, Byte), Integer))
        Me.BtnScanPort.FocusState = Bunifu.UI.WinForms.BunifuButton.BunifuButton.ButtonStates.Pressed
        Me.BtnScanPort.Font = New System.Drawing.Font("Segoe UI Semibold", 9.75!)
        Me.BtnScanPort.ForeColor = System.Drawing.Color.Black
        Me.BtnScanPort.IconLeftCursor = System.Windows.Forms.Cursors.Hand
        Me.BtnScanPort.IconMarginLeft = 11
        Me.BtnScanPort.IconPadding = 10
        Me.BtnScanPort.IconRightCursor = System.Windows.Forms.Cursors.Hand
        Me.BtnScanPort.IdleBorderColor = System.Drawing.Color.Black
        Me.BtnScanPort.IdleBorderRadius = 3
        Me.BtnScanPort.IdleBorderThickness = 1
        Me.BtnScanPort.IdleFillColor = System.Drawing.Color.Moccasin
        Me.BtnScanPort.IdleIconLeftImage = Nothing
        Me.BtnScanPort.IdleIconRightImage = Nothing
        Me.BtnScanPort.IndicateFocus = False
        Me.BtnScanPort.Location = New System.Drawing.Point(128, 173)
        Me.BtnScanPort.Name = "BtnScanPort"
        StateProperties13.BorderColor = System.Drawing.Color.Black
        StateProperties13.BorderRadius = 3
        StateProperties13.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties13.BorderThickness = 1
        StateProperties13.FillColor = System.Drawing.Color.Beige
        StateProperties13.ForeColor = System.Drawing.Color.Black
        StateProperties13.IconLeftImage = Nothing
        StateProperties13.IconRightImage = Nothing
        Me.BtnScanPort.onHoverState = StateProperties13
        StateProperties14.BorderColor = System.Drawing.Color.Black
        StateProperties14.BorderRadius = 3
        StateProperties14.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties14.BorderThickness = 1
        StateProperties14.FillColor = System.Drawing.Color.Tan
        StateProperties14.ForeColor = System.Drawing.Color.Black
        StateProperties14.IconLeftImage = Nothing
        StateProperties14.IconRightImage = Nothing
        Me.BtnScanPort.OnPressedState = StateProperties14
        Me.BtnScanPort.Size = New System.Drawing.Size(176, 56)
        Me.BtnScanPort.TabIndex = 1
        Me.BtnScanPort.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        Me.BtnScanPort.TextMarginLeft = 0
        Me.BtnScanPort.UseDefaultRadiusAndThickness = True
        '
        'CmbScanPort
        '
        Me.CmbScanPort.BackColor = System.Drawing.Color.Transparent
        Me.CmbScanPort.BaseColor = System.Drawing.Color.White
        Me.CmbScanPort.BorderColor = System.Drawing.Color.Silver
        Me.CmbScanPort.DrawMode = System.Windows.Forms.DrawMode.OwnerDrawFixed
        Me.CmbScanPort.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.CmbScanPort.FocusedColor = System.Drawing.Color.Empty
        Me.CmbScanPort.Font = New System.Drawing.Font("Tw Cen MT Condensed", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CmbScanPort.ForeColor = System.Drawing.Color.Black
        Me.CmbScanPort.FormattingEnabled = True
        Me.CmbScanPort.Location = New System.Drawing.Point(340, 188)
        Me.CmbScanPort.Name = "CmbScanPort"
        Me.CmbScanPort.OnHoverItemBaseColor = System.Drawing.Color.FromArgb(CType(CType(100, Byte), Integer), CType(CType(88, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.CmbScanPort.OnHoverItemForeColor = System.Drawing.Color.White
        Me.CmbScanPort.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.CmbScanPort.Size = New System.Drawing.Size(192, 26)
        Me.CmbScanPort.TabIndex = 3
        '
        'CmbBaud
        '
        Me.CmbBaud.BackColor = System.Drawing.Color.Transparent
        Me.CmbBaud.BaseColor = System.Drawing.Color.White
        Me.CmbBaud.BorderColor = System.Drawing.Color.Silver
        Me.CmbBaud.DrawMode = System.Windows.Forms.DrawMode.OwnerDrawFixed
        Me.CmbBaud.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.CmbBaud.FocusedColor = System.Drawing.Color.Empty
        Me.CmbBaud.Font = New System.Drawing.Font("Tw Cen MT Condensed", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CmbBaud.ForeColor = System.Drawing.Color.Black
        Me.CmbBaud.FormattingEnabled = True
        Me.CmbBaud.Location = New System.Drawing.Point(340, 267)
        Me.CmbBaud.Name = "CmbBaud"
        Me.CmbBaud.OnHoverItemBaseColor = System.Drawing.Color.FromArgb(CType(CType(100, Byte), Integer), CType(CType(88, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.CmbBaud.OnHoverItemForeColor = System.Drawing.Color.White
        Me.CmbBaud.Size = New System.Drawing.Size(192, 26)
        Me.CmbBaud.TabIndex = 4
        '
        'Lblpotentiometer
        '
        Me.Lblpotentiometer.AutoSize = True
        Me.Lblpotentiometer.Font = New System.Drawing.Font("Tw Cen MT Condensed", 30.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Lblpotentiometer.Location = New System.Drawing.Point(137, 67)
        Me.Lblpotentiometer.Name = "Lblpotentiometer"
        Me.Lblpotentiometer.Size = New System.Drawing.Size(386, 47)
        Me.Lblpotentiometer.TabIndex = 5
        Me.Lblpotentiometer.Text = "Potentiometer Value: 000"
        '
        'BunifuCustomLabel2
        '
        Me.BunifuCustomLabel2.AutoSize = True
        Me.BunifuCustomLabel2.Font = New System.Drawing.Font("Tw Cen MT Condensed", 15.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.BunifuCustomLabel2.Location = New System.Drawing.Point(170, 270)
        Me.BunifuCustomLabel2.Name = "BunifuCustomLabel2"
        Me.BunifuCustomLabel2.Size = New System.Drawing.Size(94, 23)
        Me.BunifuCustomLabel2.TabIndex = 6
        Me.BunifuCustomLabel2.Text = "BAUD RATE:"
        '
        'BtnCon
        '
        Me.BtnCon.AllowToggling = False
        Me.BtnCon.AnimationSpeed = 200
        Me.BtnCon.AutoGenerateColors = False
        Me.BtnCon.BackColor = System.Drawing.Color.Transparent
        Me.BtnCon.BackColor1 = System.Drawing.Color.Moccasin
        Me.BtnCon.BackgroundImage = CType(resources.GetObject("BtnCon.BackgroundImage"), System.Drawing.Image)
        Me.BtnCon.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        Me.BtnCon.ButtonText = "CONNECT"
        Me.BtnCon.ButtonTextMarginLeft = 0
        Me.BtnCon.ColorContrastOnClick = 45
        Me.BtnCon.ColorContrastOnHover = 45
        Me.BtnCon.Cursor = System.Windows.Forms.Cursors.Hand
        BorderEdges8.BottomLeft = True
        BorderEdges8.BottomRight = True
        BorderEdges8.TopLeft = True
        BorderEdges8.TopRight = True
        Me.BtnCon.CustomizableEdges = BorderEdges8
        Me.BtnCon.DialogResult = System.Windows.Forms.DialogResult.None
        Me.BtnCon.DisabledBorderColor = System.Drawing.Color.FromArgb(CType(CType(191, Byte), Integer), CType(CType(191, Byte), Integer), CType(CType(191, Byte), Integer))
        Me.BtnCon.DisabledFillColor = System.Drawing.Color.FromArgb(CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer))
        Me.BtnCon.DisabledForecolor = System.Drawing.Color.FromArgb(CType(CType(168, Byte), Integer), CType(CType(160, Byte), Integer), CType(CType(168, Byte), Integer))
        Me.BtnCon.FocusState = Bunifu.UI.WinForms.BunifuButton.BunifuButton.ButtonStates.Pressed
        Me.BtnCon.Font = New System.Drawing.Font("Segoe UI Semibold", 9.75!)
        Me.BtnCon.ForeColor = System.Drawing.Color.Black
        Me.BtnCon.IconLeftCursor = System.Windows.Forms.Cursors.Hand
        Me.BtnCon.IconMarginLeft = 11
        Me.BtnCon.IconPadding = 10
        Me.BtnCon.IconRightCursor = System.Windows.Forms.Cursors.Hand
        Me.BtnCon.IdleBorderColor = System.Drawing.Color.Black
        Me.BtnCon.IdleBorderRadius = 3
        Me.BtnCon.IdleBorderThickness = 1
        Me.BtnCon.IdleFillColor = System.Drawing.Color.Moccasin
        Me.BtnCon.IdleIconLeftImage = Nothing
        Me.BtnCon.IdleIconRightImage = Nothing
        Me.BtnCon.IndicateFocus = False
        Me.BtnCon.Location = New System.Drawing.Point(232, 343)
        Me.BtnCon.Name = "BtnCon"
        StateProperties15.BorderColor = System.Drawing.Color.Black
        StateProperties15.BorderRadius = 3
        StateProperties15.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties15.BorderThickness = 1
        StateProperties15.FillColor = System.Drawing.Color.Beige
        StateProperties15.ForeColor = System.Drawing.Color.Black
        StateProperties15.IconLeftImage = Nothing
        StateProperties15.IconRightImage = Nothing
        Me.BtnCon.onHoverState = StateProperties15
        StateProperties16.BorderColor = System.Drawing.Color.Black
        StateProperties16.BorderRadius = 3
        StateProperties16.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties16.BorderThickness = 1
        StateProperties16.FillColor = System.Drawing.Color.Tan
        StateProperties16.ForeColor = System.Drawing.Color.Black
        StateProperties16.IconLeftImage = Nothing
        StateProperties16.IconRightImage = Nothing
        Me.BtnCon.OnPressedState = StateProperties16
        Me.BtnCon.Size = New System.Drawing.Size(176, 56)
        Me.BtnCon.TabIndex = 7
        Me.BtnCon.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        Me.BtnCon.TextMarginLeft = 0
        Me.BtnCon.UseDefaultRadiusAndThickness = True
        '
        'BtnDiscon
        '
        Me.BtnDiscon.AllowToggling = False
        Me.BtnDiscon.AnimationSpeed = 200
        Me.BtnDiscon.AutoGenerateColors = False
        Me.BtnDiscon.BackColor = System.Drawing.Color.Transparent
        Me.BtnDiscon.BackColor1 = System.Drawing.Color.Moccasin
        Me.BtnDiscon.BackgroundImage = CType(resources.GetObject("BtnDiscon.BackgroundImage"), System.Drawing.Image)
        Me.BtnDiscon.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        Me.BtnDiscon.ButtonText = "DISCONNECT"
        Me.BtnDiscon.ButtonTextMarginLeft = 0
        Me.BtnDiscon.ColorContrastOnClick = 45
        Me.BtnDiscon.ColorContrastOnHover = 45
        Me.BtnDiscon.Cursor = System.Windows.Forms.Cursors.Hand
        BorderEdges9.BottomLeft = True
        BorderEdges9.BottomRight = True
        BorderEdges9.TopLeft = True
        BorderEdges9.TopRight = True
        Me.BtnDiscon.CustomizableEdges = BorderEdges9
        Me.BtnDiscon.DialogResult = System.Windows.Forms.DialogResult.None
        Me.BtnDiscon.DisabledBorderColor = System.Drawing.Color.FromArgb(CType(CType(191, Byte), Integer), CType(CType(191, Byte), Integer), CType(CType(191, Byte), Integer))
        Me.BtnDiscon.DisabledFillColor = System.Drawing.Color.FromArgb(CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer))
        Me.BtnDiscon.DisabledForecolor = System.Drawing.Color.FromArgb(CType(CType(168, Byte), Integer), CType(CType(160, Byte), Integer), CType(CType(168, Byte), Integer))
        Me.BtnDiscon.FocusState = Bunifu.UI.WinForms.BunifuButton.BunifuButton.ButtonStates.Pressed
        Me.BtnDiscon.Font = New System.Drawing.Font("Segoe UI Semibold", 9.75!)
        Me.BtnDiscon.ForeColor = System.Drawing.Color.Black
        Me.BtnDiscon.IconLeftCursor = System.Windows.Forms.Cursors.Hand
        Me.BtnDiscon.IconMarginLeft = 11
        Me.BtnDiscon.IconPadding = 10
        Me.BtnDiscon.IconRightCursor = System.Windows.Forms.Cursors.Hand
        Me.BtnDiscon.IdleBorderColor = System.Drawing.Color.Black
        Me.BtnDiscon.IdleBorderRadius = 3
        Me.BtnDiscon.IdleBorderThickness = 1
        Me.BtnDiscon.IdleFillColor = System.Drawing.Color.Moccasin
        Me.BtnDiscon.IdleIconLeftImage = Nothing
        Me.BtnDiscon.IdleIconRightImage = Nothing
        Me.BtnDiscon.IndicateFocus = False
        Me.BtnDiscon.Location = New System.Drawing.Point(232, 343)
        Me.BtnDiscon.Name = "BtnDiscon"
        StateProperties17.BorderColor = System.Drawing.Color.Black
        StateProperties17.BorderRadius = 3
        StateProperties17.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties17.BorderThickness = 1
        StateProperties17.FillColor = System.Drawing.Color.Beige
        StateProperties17.ForeColor = System.Drawing.Color.Black
        StateProperties17.IconLeftImage = Nothing
        StateProperties17.IconRightImage = Nothing
        Me.BtnDiscon.onHoverState = StateProperties17
        StateProperties18.BorderColor = System.Drawing.Color.Black
        StateProperties18.BorderRadius = 3
        StateProperties18.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties18.BorderThickness = 1
        StateProperties18.FillColor = System.Drawing.Color.Tan
        StateProperties18.ForeColor = System.Drawing.Color.Black
        StateProperties18.IconLeftImage = Nothing
        StateProperties18.IconRightImage = Nothing
        Me.BtnDiscon.OnPressedState = StateProperties18
        Me.BtnDiscon.Size = New System.Drawing.Size(176, 56)
        Me.BtnDiscon.TabIndex = 8
        Me.BtnDiscon.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        Me.BtnDiscon.TextMarginLeft = 0
        Me.BtnDiscon.UseDefaultRadiusAndThickness = True
        '
        'Timer1
        '
        '
        'Form2
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.OldLace
        Me.ClientSize = New System.Drawing.Size(646, 473)
        Me.Controls.Add(Me.BtnDiscon)
        Me.Controls.Add(Me.BtnCon)
        Me.Controls.Add(Me.BunifuCustomLabel2)
        Me.Controls.Add(Me.Lblpotentiometer)
        Me.Controls.Add(Me.CmbBaud)
        Me.Controls.Add(Me.CmbScanPort)
        Me.Controls.Add(Me.BtnScanPort)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "Form2"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Form2"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents BtnScanPort As Bunifu.UI.WinForms.BunifuButton.BunifuButton
    Friend WithEvents CmbScanPort As Guna.UI.WinForms.GunaComboBox
    Friend WithEvents CmbBaud As Guna.UI.WinForms.GunaComboBox
    Friend WithEvents Lblpotentiometer As Bunifu.Framework.UI.BunifuCustomLabel
    Friend WithEvents BunifuCustomLabel2 As Bunifu.Framework.UI.BunifuCustomLabel
    Friend WithEvents BtnCon As Bunifu.UI.WinForms.BunifuButton.BunifuButton
    Friend WithEvents BtnDiscon As Bunifu.UI.WinForms.BunifuButton.BunifuButton
    Friend WithEvents SerialPort1 As IO.Ports.SerialPort
    Friend WithEvents Timer1 As Timer
End Class
