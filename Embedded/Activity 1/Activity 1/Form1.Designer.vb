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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Dim BorderEdges3 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges()
        Dim StateProperties5 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim StateProperties6 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim BorderEdges4 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges()
        Dim StateProperties7 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim StateProperties8 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Me.CB_Port = New Guna.UI.WinForms.GunaComboBox()
        Me.btnON = New Bunifu.UI.WinForms.BunifuButton.BunifuButton()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.btnOFF = New Bunifu.UI.WinForms.BunifuButton.BunifuButton()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.SuspendLayout()
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
        Me.CB_Port.Location = New System.Drawing.Point(65, 129)
        Me.CB_Port.Name = "CB_Port"
        Me.CB_Port.OnHoverItemBaseColor = System.Drawing.Color.FromArgb(CType(CType(100, Byte), Integer), CType(CType(88, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.CB_Port.OnHoverItemForeColor = System.Drawing.Color.White
        Me.CB_Port.Size = New System.Drawing.Size(370, 44)
        Me.CB_Port.TabIndex = 0
        '
        'btnON
        '
        Me.btnON.AllowToggling = False
        Me.btnON.AnimationSpeed = 200
        Me.btnON.AutoGenerateColors = False
        Me.btnON.BackColor = System.Drawing.Color.Transparent
        Me.btnON.BackColor1 = System.Drawing.Color.DodgerBlue
        Me.btnON.BackgroundImage = CType(resources.GetObject("btnON.BackgroundImage"), System.Drawing.Image)
        Me.btnON.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        Me.btnON.ButtonText = "ON"
        Me.btnON.ButtonTextMarginLeft = 0
        Me.btnON.ColorContrastOnClick = 45
        Me.btnON.ColorContrastOnHover = 45
        Me.btnON.Cursor = System.Windows.Forms.Cursors.Hand
        BorderEdges3.BottomLeft = True
        BorderEdges3.BottomRight = True
        BorderEdges3.TopLeft = True
        BorderEdges3.TopRight = True
        Me.btnON.CustomizableEdges = BorderEdges3
        Me.btnON.DialogResult = System.Windows.Forms.DialogResult.None
        Me.btnON.DisabledBorderColor = System.Drawing.Color.Empty
        Me.btnON.DisabledFillColor = System.Drawing.Color.FromArgb(CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer))
        Me.btnON.DisabledForecolor = System.Drawing.Color.FromArgb(CType(CType(168, Byte), Integer), CType(CType(160, Byte), Integer), CType(CType(168, Byte), Integer))
        Me.btnON.FocusState = Bunifu.UI.WinForms.BunifuButton.BunifuButton.ButtonStates.Pressed
        Me.btnON.Font = New System.Drawing.Font("Segoe UI Semibold", 20.0!)
        Me.btnON.ForeColor = System.Drawing.Color.White
        Me.btnON.IconLeftCursor = System.Windows.Forms.Cursors.Hand
        Me.btnON.IconMarginLeft = 11
        Me.btnON.IconPadding = 10
        Me.btnON.IconRightCursor = System.Windows.Forms.Cursors.Hand
        Me.btnON.IdleBorderColor = System.Drawing.Color.DodgerBlue
        Me.btnON.IdleBorderRadius = 3
        Me.btnON.IdleBorderThickness = 1
        Me.btnON.IdleFillColor = System.Drawing.Color.DodgerBlue
        Me.btnON.IdleIconLeftImage = Nothing
        Me.btnON.IdleIconRightImage = Nothing
        Me.btnON.IndicateFocus = False
        Me.btnON.Location = New System.Drawing.Point(160, 224)
        Me.btnON.Name = "btnON"
        StateProperties5.BorderColor = System.Drawing.Color.FromArgb(CType(CType(105, Byte), Integer), CType(CType(181, Byte), Integer), CType(CType(255, Byte), Integer))
        StateProperties5.BorderRadius = 3
        StateProperties5.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties5.BorderThickness = 1
        StateProperties5.FillColor = System.Drawing.Color.FromArgb(CType(CType(105, Byte), Integer), CType(CType(181, Byte), Integer), CType(CType(255, Byte), Integer))
        StateProperties5.ForeColor = System.Drawing.Color.White
        StateProperties5.IconLeftImage = Nothing
        StateProperties5.IconRightImage = Nothing
        Me.btnON.onHoverState = StateProperties5
        StateProperties6.BorderColor = System.Drawing.Color.FromArgb(CType(CType(40, Byte), Integer), CType(CType(96, Byte), Integer), CType(CType(144, Byte), Integer))
        StateProperties6.BorderRadius = 3
        StateProperties6.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties6.BorderThickness = 1
        StateProperties6.FillColor = System.Drawing.Color.FromArgb(CType(CType(40, Byte), Integer), CType(CType(96, Byte), Integer), CType(CType(144, Byte), Integer))
        StateProperties6.ForeColor = System.Drawing.Color.White
        StateProperties6.IconLeftImage = Nothing
        StateProperties6.IconRightImage = Nothing
        Me.btnON.OnPressedState = StateProperties6
        Me.btnON.Size = New System.Drawing.Size(181, 59)
        Me.btnON.TabIndex = 1
        Me.btnON.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        Me.btnON.TextMarginLeft = 0
        Me.btnON.UseDefaultRadiusAndThickness = True
        '
        'btnOFF
        '
        Me.btnOFF.AllowToggling = False
        Me.btnOFF.AnimationSpeed = 200
        Me.btnOFF.AutoGenerateColors = False
        Me.btnOFF.BackColor = System.Drawing.Color.Transparent
        Me.btnOFF.BackColor1 = System.Drawing.Color.DodgerBlue
        Me.btnOFF.BackgroundImage = CType(resources.GetObject("btnOFF.BackgroundImage"), System.Drawing.Image)
        Me.btnOFF.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        Me.btnOFF.ButtonText = "OFF"
        Me.btnOFF.ButtonTextMarginLeft = 0
        Me.btnOFF.ColorContrastOnClick = 45
        Me.btnOFF.ColorContrastOnHover = 45
        Me.btnOFF.Cursor = System.Windows.Forms.Cursors.Hand
        BorderEdges4.BottomLeft = True
        BorderEdges4.BottomRight = True
        BorderEdges4.TopLeft = True
        BorderEdges4.TopRight = True
        Me.btnOFF.CustomizableEdges = BorderEdges4
        Me.btnOFF.DialogResult = System.Windows.Forms.DialogResult.None
        Me.btnOFF.DisabledBorderColor = System.Drawing.Color.Empty
        Me.btnOFF.DisabledFillColor = System.Drawing.Color.FromArgb(CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer))
        Me.btnOFF.DisabledForecolor = System.Drawing.Color.FromArgb(CType(CType(168, Byte), Integer), CType(CType(160, Byte), Integer), CType(CType(168, Byte), Integer))
        Me.btnOFF.FocusState = Bunifu.UI.WinForms.BunifuButton.BunifuButton.ButtonStates.Pressed
        Me.btnOFF.Font = New System.Drawing.Font("Segoe UI Semibold", 20.0!)
        Me.btnOFF.ForeColor = System.Drawing.Color.White
        Me.btnOFF.IconLeftCursor = System.Windows.Forms.Cursors.Hand
        Me.btnOFF.IconMarginLeft = 11
        Me.btnOFF.IconPadding = 10
        Me.btnOFF.IconRightCursor = System.Windows.Forms.Cursors.Hand
        Me.btnOFF.IdleBorderColor = System.Drawing.Color.DodgerBlue
        Me.btnOFF.IdleBorderRadius = 3
        Me.btnOFF.IdleBorderThickness = 1
        Me.btnOFF.IdleFillColor = System.Drawing.Color.DodgerBlue
        Me.btnOFF.IdleIconLeftImage = Nothing
        Me.btnOFF.IdleIconRightImage = Nothing
        Me.btnOFF.IndicateFocus = False
        Me.btnOFF.Location = New System.Drawing.Point(160, 310)
        Me.btnOFF.Name = "btnOFF"
        StateProperties7.BorderColor = System.Drawing.Color.FromArgb(CType(CType(105, Byte), Integer), CType(CType(181, Byte), Integer), CType(CType(255, Byte), Integer))
        StateProperties7.BorderRadius = 3
        StateProperties7.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties7.BorderThickness = 1
        StateProperties7.FillColor = System.Drawing.Color.FromArgb(CType(CType(105, Byte), Integer), CType(CType(181, Byte), Integer), CType(CType(255, Byte), Integer))
        StateProperties7.ForeColor = System.Drawing.Color.White
        StateProperties7.IconLeftImage = Nothing
        StateProperties7.IconRightImage = Nothing
        Me.btnOFF.onHoverState = StateProperties7
        StateProperties8.BorderColor = System.Drawing.Color.FromArgb(CType(CType(40, Byte), Integer), CType(CType(96, Byte), Integer), CType(CType(144, Byte), Integer))
        StateProperties8.BorderRadius = 3
        StateProperties8.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties8.BorderThickness = 1
        StateProperties8.FillColor = System.Drawing.Color.FromArgb(CType(CType(40, Byte), Integer), CType(CType(96, Byte), Integer), CType(CType(144, Byte), Integer))
        StateProperties8.ForeColor = System.Drawing.Color.White
        StateProperties8.IconLeftImage = Nothing
        StateProperties8.IconRightImage = Nothing
        Me.btnOFF.OnPressedState = StateProperties8
        Me.btnOFF.Size = New System.Drawing.Size(181, 59)
        Me.btnOFF.TabIndex = 2
        Me.btnOFF.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        Me.btnOFF.TextMarginLeft = 0
        Me.btnOFF.UseDefaultRadiusAndThickness = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 20.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(38, 81)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(424, 31)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "Arduino and Vb.Net Connection"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.White
        Me.ClientSize = New System.Drawing.Size(500, 450)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.btnOFF)
        Me.Controls.Add(Me.btnON)
        Me.Controls.Add(Me.CB_Port)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "Form1"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents CB_Port As Guna.UI.WinForms.GunaComboBox
    Friend WithEvents btnON As Bunifu.UI.WinForms.BunifuButton.BunifuButton
    Friend WithEvents SerialPort1 As IO.Ports.SerialPort
    Friend WithEvents btnOFF As Bunifu.UI.WinForms.BunifuButton.BunifuButton
    Friend WithEvents Label1 As Label
End Class
