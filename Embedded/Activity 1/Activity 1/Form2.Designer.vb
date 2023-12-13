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
        Dim BorderEdges1 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges()
        Dim StateProperties1 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim StateProperties2 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim BorderEdges2 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges()
        Dim StateProperties3 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim StateProperties4 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Me.BunifuTrackbar1 = New Bunifu.Framework.UI.BunifuTrackbar()
        Me.SendYellowVal = New Bunifu.UI.WinForms.BunifuButton.BunifuButton()
        Me.SendRedVal = New Bunifu.UI.WinForms.BunifuButton.BunifuButton()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.CB_Port = New Guna.UI.WinForms.GunaComboBox()
        Me.SuspendLayout()
        '
        'BunifuTrackbar1
        '
        Me.BunifuTrackbar1.BackColor = System.Drawing.Color.Transparent
        Me.BunifuTrackbar1.BackgroudColor = System.Drawing.Color.DarkGray
        Me.BunifuTrackbar1.BorderRadius = 0
        Me.BunifuTrackbar1.IndicatorColor = System.Drawing.Color.Yellow
        Me.BunifuTrackbar1.Location = New System.Drawing.Point(12, 189)
        Me.BunifuTrackbar1.MaximumValue = 255
        Me.BunifuTrackbar1.MinimumValue = 0
        Me.BunifuTrackbar1.Name = "BunifuTrackbar1"
        Me.BunifuTrackbar1.Size = New System.Drawing.Size(415, 28)
        Me.BunifuTrackbar1.SliderRadius = 0
        Me.BunifuTrackbar1.TabIndex = 0
        Me.BunifuTrackbar1.Value = 0
        '
        'SendYellowVal
        '
        Me.SendYellowVal.AllowToggling = False
        Me.SendYellowVal.AnimationSpeed = 200
        Me.SendYellowVal.AutoGenerateColors = False
        Me.SendYellowVal.BackColor = System.Drawing.Color.Transparent
        Me.SendYellowVal.BackColor1 = System.Drawing.Color.FromArgb(CType(CType(241, Byte), Integer), CType(CType(196, Byte), Integer), CType(CType(15, Byte), Integer))
        Me.SendYellowVal.BackgroundImage = CType(resources.GetObject("SendYellowVal.BackgroundImage"), System.Drawing.Image)
        Me.SendYellowVal.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        Me.SendYellowVal.ButtonText = "Turn ON"
        Me.SendYellowVal.ButtonTextMarginLeft = 0
        Me.SendYellowVal.ColorContrastOnClick = 45
        Me.SendYellowVal.ColorContrastOnHover = 45
        Me.SendYellowVal.Cursor = System.Windows.Forms.Cursors.Hand
        BorderEdges1.BottomLeft = True
        BorderEdges1.BottomRight = True
        BorderEdges1.TopLeft = True
        BorderEdges1.TopRight = True
        Me.SendYellowVal.CustomizableEdges = BorderEdges1
        Me.SendYellowVal.DialogResult = System.Windows.Forms.DialogResult.None
        Me.SendYellowVal.DisabledBorderColor = System.Drawing.Color.Empty
        Me.SendYellowVal.DisabledFillColor = System.Drawing.Color.FromArgb(CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer))
        Me.SendYellowVal.DisabledForecolor = System.Drawing.Color.FromArgb(CType(CType(168, Byte), Integer), CType(CType(160, Byte), Integer), CType(CType(168, Byte), Integer))
        Me.SendYellowVal.FocusState = Bunifu.UI.WinForms.BunifuButton.BunifuButton.ButtonStates.Pressed
        Me.SendYellowVal.Font = New System.Drawing.Font("Segoe UI Semibold", 9.75!)
        Me.SendYellowVal.ForeColor = System.Drawing.Color.White
        Me.SendYellowVal.IconLeftCursor = System.Windows.Forms.Cursors.Hand
        Me.SendYellowVal.IconMarginLeft = 11
        Me.SendYellowVal.IconPadding = 10
        Me.SendYellowVal.IconRightCursor = System.Windows.Forms.Cursors.Hand
        Me.SendYellowVal.IdleBorderColor = System.Drawing.Color.FromArgb(CType(CType(241, Byte), Integer), CType(CType(196, Byte), Integer), CType(CType(15, Byte), Integer))
        Me.SendYellowVal.IdleBorderRadius = 3
        Me.SendYellowVal.IdleBorderThickness = 1
        Me.SendYellowVal.IdleFillColor = System.Drawing.Color.FromArgb(CType(CType(241, Byte), Integer), CType(CType(196, Byte), Integer), CType(CType(15, Byte), Integer))
        Me.SendYellowVal.IdleIconLeftImage = Nothing
        Me.SendYellowVal.IdleIconRightImage = Nothing
        Me.SendYellowVal.IndicateFocus = False
        Me.SendYellowVal.Location = New System.Drawing.Point(139, 236)
        Me.SendYellowVal.Name = "SendYellowVal"
        StateProperties1.BorderColor = System.Drawing.Color.Yellow
        StateProperties1.BorderRadius = 3
        StateProperties1.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties1.BorderThickness = 1
        StateProperties1.FillColor = System.Drawing.Color.Yellow
        StateProperties1.ForeColor = System.Drawing.Color.White
        StateProperties1.IconLeftImage = Nothing
        StateProperties1.IconRightImage = Nothing
        Me.SendYellowVal.onHoverState = StateProperties1
        StateProperties2.BorderColor = System.Drawing.Color.FromArgb(CType(CType(243, Byte), Integer), CType(CType(156, Byte), Integer), CType(CType(18, Byte), Integer))
        StateProperties2.BorderRadius = 3
        StateProperties2.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties2.BorderThickness = 1
        StateProperties2.FillColor = System.Drawing.Color.FromArgb(CType(CType(243, Byte), Integer), CType(CType(156, Byte), Integer), CType(CType(18, Byte), Integer))
        StateProperties2.ForeColor = System.Drawing.Color.White
        StateProperties2.IconLeftImage = Nothing
        StateProperties2.IconRightImage = Nothing
        Me.SendYellowVal.OnPressedState = StateProperties2
        Me.SendYellowVal.Size = New System.Drawing.Size(154, 35)
        Me.SendYellowVal.TabIndex = 11
        Me.SendYellowVal.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        Me.SendYellowVal.TextMarginLeft = 0
        Me.SendYellowVal.UseDefaultRadiusAndThickness = True
        '
        'SendRedVal
        '
        Me.SendRedVal.AllowToggling = False
        Me.SendRedVal.AnimationSpeed = 200
        Me.SendRedVal.AutoGenerateColors = False
        Me.SendRedVal.BackColor = System.Drawing.Color.Transparent
        Me.SendRedVal.BackColor1 = System.Drawing.Color.FromArgb(CType(CType(231, Byte), Integer), CType(CType(76, Byte), Integer), CType(CType(60, Byte), Integer))
        Me.SendRedVal.BackgroundImage = CType(resources.GetObject("SendRedVal.BackgroundImage"), System.Drawing.Image)
        Me.SendRedVal.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        Me.SendRedVal.ButtonText = "Turn OFF"
        Me.SendRedVal.ButtonTextMarginLeft = 0
        Me.SendRedVal.ColorContrastOnClick = 45
        Me.SendRedVal.ColorContrastOnHover = 45
        Me.SendRedVal.Cursor = System.Windows.Forms.Cursors.Hand
        BorderEdges2.BottomLeft = True
        BorderEdges2.BottomRight = True
        BorderEdges2.TopLeft = True
        BorderEdges2.TopRight = True
        Me.SendRedVal.CustomizableEdges = BorderEdges2
        Me.SendRedVal.DialogResult = System.Windows.Forms.DialogResult.None
        Me.SendRedVal.DisabledBorderColor = System.Drawing.Color.Empty
        Me.SendRedVal.DisabledFillColor = System.Drawing.Color.FromArgb(CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer))
        Me.SendRedVal.DisabledForecolor = System.Drawing.Color.FromArgb(CType(CType(168, Byte), Integer), CType(CType(160, Byte), Integer), CType(CType(168, Byte), Integer))
        Me.SendRedVal.FocusState = Bunifu.UI.WinForms.BunifuButton.BunifuButton.ButtonStates.Pressed
        Me.SendRedVal.Font = New System.Drawing.Font("Segoe UI Semibold", 9.75!)
        Me.SendRedVal.ForeColor = System.Drawing.Color.White
        Me.SendRedVal.IconLeftCursor = System.Windows.Forms.Cursors.Hand
        Me.SendRedVal.IconMarginLeft = 11
        Me.SendRedVal.IconPadding = 10
        Me.SendRedVal.IconRightCursor = System.Windows.Forms.Cursors.Hand
        Me.SendRedVal.IdleBorderColor = System.Drawing.Color.FromArgb(CType(CType(231, Byte), Integer), CType(CType(76, Byte), Integer), CType(CType(60, Byte), Integer))
        Me.SendRedVal.IdleBorderRadius = 3
        Me.SendRedVal.IdleBorderThickness = 1
        Me.SendRedVal.IdleFillColor = System.Drawing.Color.FromArgb(CType(CType(231, Byte), Integer), CType(CType(76, Byte), Integer), CType(CType(60, Byte), Integer))
        Me.SendRedVal.IdleIconLeftImage = Nothing
        Me.SendRedVal.IdleIconRightImage = Nothing
        Me.SendRedVal.IndicateFocus = False
        Me.SendRedVal.Location = New System.Drawing.Point(139, 292)
        Me.SendRedVal.Name = "SendRedVal"
        StateProperties3.BorderColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(128, Byte), Integer))
        StateProperties3.BorderRadius = 3
        StateProperties3.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties3.BorderThickness = 1
        StateProperties3.FillColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(128, Byte), Integer))
        StateProperties3.ForeColor = System.Drawing.Color.White
        StateProperties3.IconLeftImage = Nothing
        StateProperties3.IconRightImage = Nothing
        Me.SendRedVal.onHoverState = StateProperties3
        StateProperties4.BorderColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(57, Byte), Integer), CType(CType(43, Byte), Integer))
        StateProperties4.BorderRadius = 3
        StateProperties4.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties4.BorderThickness = 1
        StateProperties4.FillColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(57, Byte), Integer), CType(CType(43, Byte), Integer))
        StateProperties4.ForeColor = System.Drawing.Color.White
        StateProperties4.IconLeftImage = Nothing
        StateProperties4.IconRightImage = Nothing
        Me.SendRedVal.OnPressedState = StateProperties4
        Me.SendRedVal.Size = New System.Drawing.Size(154, 35)
        Me.SendRedVal.TabIndex = 12
        Me.SendRedVal.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        Me.SendRedVal.TextMarginLeft = 0
        Me.SendRedVal.UseDefaultRadiusAndThickness = True
        '
        'CB_Port
        '
        Me.CB_Port.BackColor = System.Drawing.Color.Transparent
        Me.CB_Port.BaseColor = System.Drawing.Color.White
        Me.CB_Port.BorderColor = System.Drawing.Color.Silver
        Me.CB_Port.DrawMode = System.Windows.Forms.DrawMode.OwnerDrawFixed
        Me.CB_Port.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.CB_Port.FocusedColor = System.Drawing.Color.Empty
        Me.CB_Port.Font = New System.Drawing.Font("Segoe UI", 20.0!)
        Me.CB_Port.ForeColor = System.Drawing.Color.Black
        Me.CB_Port.FormattingEnabled = True
        Me.CB_Port.Location = New System.Drawing.Point(42, 123)
        Me.CB_Port.Name = "CB_Port"
        Me.CB_Port.OnHoverItemBaseColor = System.Drawing.Color.FromArgb(CType(CType(100, Byte), Integer), CType(CType(88, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.CB_Port.OnHoverItemForeColor = System.Drawing.Color.White
        Me.CB_Port.Size = New System.Drawing.Size(370, 44)
        Me.CB_Port.TabIndex = 13
        '
        'Form2
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(453, 343)
        Me.Controls.Add(Me.CB_Port)
        Me.Controls.Add(Me.SendRedVal)
        Me.Controls.Add(Me.SendYellowVal)
        Me.Controls.Add(Me.BunifuTrackbar1)
        Me.Name = "Form2"
        Me.Text = "Form2"
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents BunifuTrackbar1 As Bunifu.Framework.UI.BunifuTrackbar
    Private WithEvents SendYellowVal As Bunifu.UI.WinForms.BunifuButton.BunifuButton
    Private WithEvents SendRedVal As Bunifu.UI.WinForms.BunifuButton.BunifuButton
    Friend WithEvents SerialPort1 As IO.Ports.SerialPort
    Friend WithEvents CB_Port As Guna.UI.WinForms.GunaComboBox
End Class
