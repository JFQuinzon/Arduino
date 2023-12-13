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
        Dim BorderEdges1 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges()
        Dim StateProperties1 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim StateProperties2 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim BorderEdges2 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges()
        Dim StateProperties3 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim StateProperties4 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim BorderEdges3 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderEdges()
        Dim StateProperties5 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim StateProperties6 As Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties = New Bunifu.UI.WinForms.BunifuButton.BunifuButton.StateProperties()
        Dim ChartArea1 As System.Windows.Forms.DataVisualization.Charting.ChartArea = New System.Windows.Forms.DataVisualization.Charting.ChartArea()
        Dim Legend1 As System.Windows.Forms.DataVisualization.Charting.Legend = New System.Windows.Forms.DataVisualization.Charting.Legend()
        Dim Series1 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Dim ChartArea2 As System.Windows.Forms.DataVisualization.Charting.ChartArea = New System.Windows.Forms.DataVisualization.Charting.ChartArea()
        Dim Legend2 As System.Windows.Forms.DataVisualization.Charting.Legend = New System.Windows.Forms.DataVisualization.Charting.Legend()
        Dim Series2 As System.Windows.Forms.DataVisualization.Charting.Series = New System.Windows.Forms.DataVisualization.Charting.Series()
        Me.PanelConnection = New System.Windows.Forms.Panel()
        Me.ButtonConnect = New Bunifu.UI.WinForms.BunifuButton.BunifuButton()
        Me.ComboBaudRate = New Guna.UI.WinForms.GunaComboBox()
        Me.LabelBaudRate = New System.Windows.Forms.Label()
        Me.ComboBoxPort = New Guna.UI.WinForms.GunaComboBox()
        Me.LabelConnectionTitle = New System.Windows.Forms.Label()
        Me.ButtonScanPort = New Bunifu.UI.WinForms.BunifuButton.BunifuButton()
        Me.ButtonDisconnect = New Bunifu.UI.WinForms.BunifuButton.BunifuButton()
        Me.Panel1 = New System.Windows.Forms.Panel()
        Me.CircleProgressbarHumidity = New Bunifu.Framework.UI.BunifuCircleProgressbar()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.PanelTemperature = New System.Windows.Forms.Panel()
        Me.LabelTempMin = New System.Windows.Forms.Label()
        Me.LabelTempMax = New System.Windows.Forms.Label()
        Me.LabelTemperature = New System.Windows.Forms.Label()
        Me.VProgressbarTemperature = New Guna.UI.WinForms.GunaVProgressBar()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Chart1 = New System.Windows.Forms.DataVisualization.Charting.Chart()
        Me.Chart2 = New System.Windows.Forms.DataVisualization.Charting.Chart()
        Me.PictureBox2 = New System.Windows.Forms.PictureBox()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.LabelStatus = New System.Windows.Forms.Label()
        Me.PictureBoxStatusConnection = New System.Windows.Forms.PictureBox()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.TimerSerial = New System.Windows.Forms.Timer(Me.components)
        Me.PanelConnection.SuspendLayout()
        Me.Panel1.SuspendLayout()
        Me.PanelTemperature.SuspendLayout()
        CType(Me.Chart1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Chart2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBoxStatusConnection, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'PanelConnection
        '
        Me.PanelConnection.BackColor = System.Drawing.Color.White
        Me.PanelConnection.Controls.Add(Me.ButtonConnect)
        Me.PanelConnection.Controls.Add(Me.ComboBaudRate)
        Me.PanelConnection.Controls.Add(Me.LabelBaudRate)
        Me.PanelConnection.Controls.Add(Me.ComboBoxPort)
        Me.PanelConnection.Controls.Add(Me.LabelConnectionTitle)
        Me.PanelConnection.Controls.Add(Me.ButtonScanPort)
        Me.PanelConnection.Controls.Add(Me.ButtonDisconnect)
        Me.PanelConnection.Location = New System.Drawing.Point(12, 12)
        Me.PanelConnection.Name = "PanelConnection"
        Me.PanelConnection.Size = New System.Drawing.Size(531, 138)
        Me.PanelConnection.TabIndex = 0
        '
        'ButtonConnect
        '
        Me.ButtonConnect.AllowToggling = False
        Me.ButtonConnect.AnimationSpeed = 200
        Me.ButtonConnect.AutoGenerateColors = False
        Me.ButtonConnect.BackColor = System.Drawing.Color.Transparent
        Me.ButtonConnect.BackColor1 = System.Drawing.Color.Green
        Me.ButtonConnect.BackgroundImage = CType(resources.GetObject("ButtonConnect.BackgroundImage"), System.Drawing.Image)
        Me.ButtonConnect.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        Me.ButtonConnect.ButtonText = "Connect"
        Me.ButtonConnect.ButtonTextMarginLeft = 0
        Me.ButtonConnect.ColorContrastOnClick = 45
        Me.ButtonConnect.ColorContrastOnHover = 45
        Me.ButtonConnect.Cursor = System.Windows.Forms.Cursors.Hand
        BorderEdges1.BottomLeft = True
        BorderEdges1.BottomRight = True
        BorderEdges1.TopLeft = True
        BorderEdges1.TopRight = True
        Me.ButtonConnect.CustomizableEdges = BorderEdges1
        Me.ButtonConnect.DialogResult = System.Windows.Forms.DialogResult.None
        Me.ButtonConnect.DisabledBorderColor = System.Drawing.Color.Empty
        Me.ButtonConnect.DisabledFillColor = System.Drawing.Color.FromArgb(CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer))
        Me.ButtonConnect.DisabledForecolor = System.Drawing.Color.FromArgb(CType(CType(168, Byte), Integer), CType(CType(160, Byte), Integer), CType(CType(168, Byte), Integer))
        Me.ButtonConnect.FocusState = Bunifu.UI.WinForms.BunifuButton.BunifuButton.ButtonStates.Pressed
        Me.ButtonConnect.Font = New System.Drawing.Font("Segoe UI Semibold", 12.0!)
        Me.ButtonConnect.ForeColor = System.Drawing.Color.White
        Me.ButtonConnect.IconLeftCursor = System.Windows.Forms.Cursors.Hand
        Me.ButtonConnect.IconMarginLeft = 11
        Me.ButtonConnect.IconPadding = 10
        Me.ButtonConnect.IconRightCursor = System.Windows.Forms.Cursors.Hand
        Me.ButtonConnect.IdleBorderColor = System.Drawing.Color.Green
        Me.ButtonConnect.IdleBorderRadius = 3
        Me.ButtonConnect.IdleBorderThickness = 1
        Me.ButtonConnect.IdleFillColor = System.Drawing.Color.Green
        Me.ButtonConnect.IdleIconLeftImage = Nothing
        Me.ButtonConnect.IdleIconRightImage = Nothing
        Me.ButtonConnect.IndicateFocus = False
        Me.ButtonConnect.Location = New System.Drawing.Point(20, 93)
        Me.ButtonConnect.Name = "ButtonConnect"
        StateProperties1.BorderColor = System.Drawing.Color.Cyan
        StateProperties1.BorderRadius = 3
        StateProperties1.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties1.BorderThickness = 1
        StateProperties1.FillColor = System.Drawing.Color.Cyan
        StateProperties1.ForeColor = System.Drawing.Color.Black
        StateProperties1.IconLeftImage = Nothing
        StateProperties1.IconRightImage = Nothing
        Me.ButtonConnect.onHoverState = StateProperties1
        StateProperties2.BorderColor = System.Drawing.Color.Cyan
        StateProperties2.BorderRadius = 3
        StateProperties2.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties2.BorderThickness = 1
        StateProperties2.FillColor = System.Drawing.Color.Cyan
        StateProperties2.ForeColor = System.Drawing.Color.Black
        StateProperties2.IconLeftImage = Nothing
        StateProperties2.IconRightImage = Nothing
        Me.ButtonConnect.OnPressedState = StateProperties2
        Me.ButtonConnect.Size = New System.Drawing.Size(493, 30)
        Me.ButtonConnect.TabIndex = 5
        Me.ButtonConnect.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        Me.ButtonConnect.TextMarginLeft = 0
        Me.ButtonConnect.UseDefaultRadiusAndThickness = True
        '
        'ComboBaudRate
        '
        Me.ComboBaudRate.BackColor = System.Drawing.Color.Transparent
        Me.ComboBaudRate.BaseColor = System.Drawing.Color.White
        Me.ComboBaudRate.BorderColor = System.Drawing.Color.Silver
        Me.ComboBaudRate.DrawMode = System.Windows.Forms.DrawMode.OwnerDrawFixed
        Me.ComboBaudRate.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBaudRate.FocusedColor = System.Drawing.Color.Empty
        Me.ComboBaudRate.Font = New System.Drawing.Font("Segoe UI", 12.0!)
        Me.ComboBaudRate.ForeColor = System.Drawing.Color.Black
        Me.ComboBaudRate.FormattingEnabled = True
        Me.ComboBaudRate.Items.AddRange(New Object() {"9600", "14400", "19200", "38400", "57600", "115200"})
        Me.ComboBaudRate.Location = New System.Drawing.Point(392, 57)
        Me.ComboBaudRate.Name = "ComboBaudRate"
        Me.ComboBaudRate.OnHoverItemBaseColor = System.Drawing.Color.FromArgb(CType(CType(100, Byte), Integer), CType(CType(88, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.ComboBaudRate.OnHoverItemForeColor = System.Drawing.Color.White
        Me.ComboBaudRate.Size = New System.Drawing.Size(120, 30)
        Me.ComboBaudRate.TabIndex = 4
        '
        'LabelBaudRate
        '
        Me.LabelBaudRate.AutoSize = True
        Me.LabelBaudRate.Font = New System.Drawing.Font("Segoe UI Semibold", 12.0!)
        Me.LabelBaudRate.ForeColor = System.Drawing.Color.Black
        Me.LabelBaudRate.Location = New System.Drawing.Point(303, 62)
        Me.LabelBaudRate.Name = "LabelBaudRate"
        Me.LabelBaudRate.Size = New System.Drawing.Size(88, 21)
        Me.LabelBaudRate.TabIndex = 3
        Me.LabelBaudRate.Text = "Baud Rate:"
        '
        'ComboBoxPort
        '
        Me.ComboBoxPort.BackColor = System.Drawing.Color.Transparent
        Me.ComboBoxPort.BaseColor = System.Drawing.Color.White
        Me.ComboBoxPort.BorderColor = System.Drawing.Color.Silver
        Me.ComboBoxPort.DrawMode = System.Windows.Forms.DrawMode.OwnerDrawFixed
        Me.ComboBoxPort.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.ComboBoxPort.FocusedColor = System.Drawing.Color.Empty
        Me.ComboBoxPort.Font = New System.Drawing.Font("Segoe UI", 12.0!)
        Me.ComboBoxPort.ForeColor = System.Drawing.Color.Black
        Me.ComboBoxPort.FormattingEnabled = True
        Me.ComboBoxPort.Location = New System.Drawing.Point(179, 57)
        Me.ComboBoxPort.Name = "ComboBoxPort"
        Me.ComboBoxPort.OnHoverItemBaseColor = System.Drawing.Color.FromArgb(CType(CType(100, Byte), Integer), CType(CType(88, Byte), Integer), CType(CType(255, Byte), Integer))
        Me.ComboBoxPort.OnHoverItemForeColor = System.Drawing.Color.White
        Me.ComboBoxPort.Size = New System.Drawing.Size(120, 30)
        Me.ComboBoxPort.TabIndex = 2
        '
        'LabelConnectionTitle
        '
        Me.LabelConnectionTitle.AutoSize = True
        Me.LabelConnectionTitle.Font = New System.Drawing.Font("Segoe UI Black", 17.0!)
        Me.LabelConnectionTitle.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(206, Byte), Integer), CType(CType(230, Byte), Integer))
        Me.LabelConnectionTitle.Location = New System.Drawing.Point(196, 17)
        Me.LabelConnectionTitle.Name = "LabelConnectionTitle"
        Me.LabelConnectionTitle.Size = New System.Drawing.Size(141, 31)
        Me.LabelConnectionTitle.TabIndex = 1
        Me.LabelConnectionTitle.Text = "Connection"
        '
        'ButtonScanPort
        '
        Me.ButtonScanPort.AllowToggling = False
        Me.ButtonScanPort.AnimationSpeed = 200
        Me.ButtonScanPort.AutoGenerateColors = False
        Me.ButtonScanPort.BackColor = System.Drawing.Color.Transparent
        Me.ButtonScanPort.BackColor1 = System.Drawing.Color.DodgerBlue
        Me.ButtonScanPort.BackgroundImage = CType(resources.GetObject("ButtonScanPort.BackgroundImage"), System.Drawing.Image)
        Me.ButtonScanPort.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        Me.ButtonScanPort.ButtonText = "Scan Port"
        Me.ButtonScanPort.ButtonTextMarginLeft = 0
        Me.ButtonScanPort.ColorContrastOnClick = 45
        Me.ButtonScanPort.ColorContrastOnHover = 45
        Me.ButtonScanPort.Cursor = System.Windows.Forms.Cursors.Hand
        BorderEdges2.BottomLeft = True
        BorderEdges2.BottomRight = True
        BorderEdges2.TopLeft = True
        BorderEdges2.TopRight = True
        Me.ButtonScanPort.CustomizableEdges = BorderEdges2
        Me.ButtonScanPort.DialogResult = System.Windows.Forms.DialogResult.None
        Me.ButtonScanPort.DisabledBorderColor = System.Drawing.Color.Empty
        Me.ButtonScanPort.DisabledFillColor = System.Drawing.Color.FromArgb(CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer))
        Me.ButtonScanPort.DisabledForecolor = System.Drawing.Color.FromArgb(CType(CType(168, Byte), Integer), CType(CType(160, Byte), Integer), CType(CType(168, Byte), Integer))
        Me.ButtonScanPort.FocusState = Bunifu.UI.WinForms.BunifuButton.BunifuButton.ButtonStates.Pressed
        Me.ButtonScanPort.Font = New System.Drawing.Font("Segoe UI Semibold", 12.0!)
        Me.ButtonScanPort.ForeColor = System.Drawing.Color.White
        Me.ButtonScanPort.IconLeftCursor = System.Windows.Forms.Cursors.Hand
        Me.ButtonScanPort.IconMarginLeft = 11
        Me.ButtonScanPort.IconPadding = 10
        Me.ButtonScanPort.IconRightCursor = System.Windows.Forms.Cursors.Hand
        Me.ButtonScanPort.IdleBorderColor = System.Drawing.Color.DodgerBlue
        Me.ButtonScanPort.IdleBorderRadius = 3
        Me.ButtonScanPort.IdleBorderThickness = 1
        Me.ButtonScanPort.IdleFillColor = System.Drawing.Color.DodgerBlue
        Me.ButtonScanPort.IdleIconLeftImage = Nothing
        Me.ButtonScanPort.IdleIconRightImage = Nothing
        Me.ButtonScanPort.IndicateFocus = False
        Me.ButtonScanPort.Location = New System.Drawing.Point(20, 57)
        Me.ButtonScanPort.Name = "ButtonScanPort"
        StateProperties3.BorderColor = System.Drawing.Color.FromArgb(CType(CType(105, Byte), Integer), CType(CType(181, Byte), Integer), CType(CType(255, Byte), Integer))
        StateProperties3.BorderRadius = 3
        StateProperties3.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties3.BorderThickness = 1
        StateProperties3.FillColor = System.Drawing.Color.FromArgb(CType(CType(105, Byte), Integer), CType(CType(181, Byte), Integer), CType(CType(255, Byte), Integer))
        StateProperties3.ForeColor = System.Drawing.Color.White
        StateProperties3.IconLeftImage = Nothing
        StateProperties3.IconRightImage = Nothing
        Me.ButtonScanPort.onHoverState = StateProperties3
        StateProperties4.BorderColor = System.Drawing.Color.FromArgb(CType(CType(40, Byte), Integer), CType(CType(96, Byte), Integer), CType(CType(144, Byte), Integer))
        StateProperties4.BorderRadius = 3
        StateProperties4.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties4.BorderThickness = 1
        StateProperties4.FillColor = System.Drawing.Color.FromArgb(CType(CType(40, Byte), Integer), CType(CType(96, Byte), Integer), CType(CType(144, Byte), Integer))
        StateProperties4.ForeColor = System.Drawing.Color.White
        StateProperties4.IconLeftImage = Nothing
        StateProperties4.IconRightImage = Nothing
        Me.ButtonScanPort.OnPressedState = StateProperties4
        Me.ButtonScanPort.Size = New System.Drawing.Size(153, 30)
        Me.ButtonScanPort.TabIndex = 0
        Me.ButtonScanPort.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        Me.ButtonScanPort.TextMarginLeft = 0
        Me.ButtonScanPort.UseDefaultRadiusAndThickness = True
        '
        'ButtonDisconnect
        '
        Me.ButtonDisconnect.AllowToggling = False
        Me.ButtonDisconnect.AnimationSpeed = 200
        Me.ButtonDisconnect.AutoGenerateColors = False
        Me.ButtonDisconnect.BackColor = System.Drawing.Color.Transparent
        Me.ButtonDisconnect.BackColor1 = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.ButtonDisconnect.BackgroundImage = CType(resources.GetObject("ButtonDisconnect.BackgroundImage"), System.Drawing.Image)
        Me.ButtonDisconnect.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        Me.ButtonDisconnect.ButtonText = "Disconnect"
        Me.ButtonDisconnect.ButtonTextMarginLeft = 0
        Me.ButtonDisconnect.ColorContrastOnClick = 45
        Me.ButtonDisconnect.ColorContrastOnHover = 45
        Me.ButtonDisconnect.Cursor = System.Windows.Forms.Cursors.Hand
        BorderEdges3.BottomLeft = True
        BorderEdges3.BottomRight = True
        BorderEdges3.TopLeft = True
        BorderEdges3.TopRight = True
        Me.ButtonDisconnect.CustomizableEdges = BorderEdges3
        Me.ButtonDisconnect.DialogResult = System.Windows.Forms.DialogResult.None
        Me.ButtonDisconnect.DisabledBorderColor = System.Drawing.Color.Empty
        Me.ButtonDisconnect.DisabledFillColor = System.Drawing.Color.FromArgb(CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer), CType(CType(204, Byte), Integer))
        Me.ButtonDisconnect.DisabledForecolor = System.Drawing.Color.FromArgb(CType(CType(168, Byte), Integer), CType(CType(160, Byte), Integer), CType(CType(168, Byte), Integer))
        Me.ButtonDisconnect.FocusState = Bunifu.UI.WinForms.BunifuButton.BunifuButton.ButtonStates.Pressed
        Me.ButtonDisconnect.Font = New System.Drawing.Font("Segoe UI Semibold", 12.0!)
        Me.ButtonDisconnect.ForeColor = System.Drawing.Color.White
        Me.ButtonDisconnect.IconLeftCursor = System.Windows.Forms.Cursors.Hand
        Me.ButtonDisconnect.IconMarginLeft = 11
        Me.ButtonDisconnect.IconPadding = 10
        Me.ButtonDisconnect.IconRightCursor = System.Windows.Forms.Cursors.Hand
        Me.ButtonDisconnect.IdleBorderColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.ButtonDisconnect.IdleBorderRadius = 3
        Me.ButtonDisconnect.IdleBorderThickness = 1
        Me.ButtonDisconnect.IdleFillColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.ButtonDisconnect.IdleIconLeftImage = Nothing
        Me.ButtonDisconnect.IdleIconRightImage = Nothing
        Me.ButtonDisconnect.IndicateFocus = False
        Me.ButtonDisconnect.Location = New System.Drawing.Point(20, 93)
        Me.ButtonDisconnect.Name = "ButtonDisconnect"
        StateProperties5.BorderColor = System.Drawing.Color.Red
        StateProperties5.BorderRadius = 3
        StateProperties5.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties5.BorderThickness = 1
        StateProperties5.FillColor = System.Drawing.Color.Red
        StateProperties5.ForeColor = System.Drawing.Color.Black
        StateProperties5.IconLeftImage = Nothing
        StateProperties5.IconRightImage = Nothing
        Me.ButtonDisconnect.onHoverState = StateProperties5
        StateProperties6.BorderColor = System.Drawing.Color.Red
        StateProperties6.BorderRadius = 3
        StateProperties6.BorderStyle = Bunifu.UI.WinForms.BunifuButton.BunifuButton.BorderStyles.Solid
        StateProperties6.BorderThickness = 1
        StateProperties6.FillColor = System.Drawing.Color.Red
        StateProperties6.ForeColor = System.Drawing.Color.Black
        StateProperties6.IconLeftImage = Nothing
        StateProperties6.IconRightImage = Nothing
        Me.ButtonDisconnect.OnPressedState = StateProperties6
        Me.ButtonDisconnect.Size = New System.Drawing.Size(493, 30)
        Me.ButtonDisconnect.TabIndex = 6
        Me.ButtonDisconnect.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        Me.ButtonDisconnect.TextMarginLeft = 0
        Me.ButtonDisconnect.UseDefaultRadiusAndThickness = True
        '
        'Panel1
        '
        Me.Panel1.BackColor = System.Drawing.Color.White
        Me.Panel1.Controls.Add(Me.CircleProgressbarHumidity)
        Me.Panel1.Controls.Add(Me.Label1)
        Me.Panel1.Location = New System.Drawing.Point(12, 164)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(260, 260)
        Me.Panel1.TabIndex = 1
        '
        'CircleProgressbarHumidity
        '
        Me.CircleProgressbarHumidity.animated = False
        Me.CircleProgressbarHumidity.animationIterval = 5
        Me.CircleProgressbarHumidity.animationSpeed = 300
        Me.CircleProgressbarHumidity.BackColor = System.Drawing.Color.White
        Me.CircleProgressbarHumidity.BackgroundImage = CType(resources.GetObject("CircleProgressbarHumidity.BackgroundImage"), System.Drawing.Image)
        Me.CircleProgressbarHumidity.Font = New System.Drawing.Font("Segoe UI Semibold", 25.0!)
        Me.CircleProgressbarHumidity.ForeColor = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        Me.CircleProgressbarHumidity.LabelVisible = True
        Me.CircleProgressbarHumidity.LineProgressThickness = 8
        Me.CircleProgressbarHumidity.LineThickness = 5
        Me.CircleProgressbarHumidity.Location = New System.Drawing.Point(31, 46)
        Me.CircleProgressbarHumidity.Margin = New System.Windows.Forms.Padding(4, 5, 4, 5)
        Me.CircleProgressbarHumidity.MaxValue = 100
        Me.CircleProgressbarHumidity.Name = "CircleProgressbarHumidity"
        Me.CircleProgressbarHumidity.ProgressBackColor = System.Drawing.Color.Gainsboro
        Me.CircleProgressbarHumidity.ProgressColor = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        Me.CircleProgressbarHumidity.Size = New System.Drawing.Size(198, 198)
        Me.CircleProgressbarHumidity.TabIndex = 2
        Me.CircleProgressbarHumidity.Value = 51
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Segoe UI Black", 14.0!)
        Me.Label1.ForeColor = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        Me.Label1.Location = New System.Drawing.Point(77, 16)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(100, 25)
        Me.Label1.TabIndex = 6
        Me.Label1.Text = "Humidity"
        '
        'PanelTemperature
        '
        Me.PanelTemperature.BackColor = System.Drawing.Color.White
        Me.PanelTemperature.Controls.Add(Me.LabelTempMin)
        Me.PanelTemperature.Controls.Add(Me.LabelTempMax)
        Me.PanelTemperature.Controls.Add(Me.LabelTemperature)
        Me.PanelTemperature.Controls.Add(Me.VProgressbarTemperature)
        Me.PanelTemperature.Controls.Add(Me.Label2)
        Me.PanelTemperature.Location = New System.Drawing.Point(283, 164)
        Me.PanelTemperature.Name = "PanelTemperature"
        Me.PanelTemperature.Size = New System.Drawing.Size(260, 260)
        Me.PanelTemperature.TabIndex = 7
        '
        'LabelTempMin
        '
        Me.LabelTempMin.AutoSize = True
        Me.LabelTempMin.Font = New System.Drawing.Font("Segoe UI Black", 12.0!)
        Me.LabelTempMin.ForeColor = System.Drawing.Color.Gray
        Me.LabelTempMin.Location = New System.Drawing.Point(83, 219)
        Me.LabelTempMin.Name = "LabelTempMin"
        Me.LabelTempMin.Size = New System.Drawing.Size(57, 21)
        Me.LabelTempMin.TabIndex = 11
        Me.LabelTempMin.Text = "-20 °C"
        '
        'LabelTempMax
        '
        Me.LabelTempMax.AutoSize = True
        Me.LabelTempMax.Font = New System.Drawing.Font("Segoe UI Black", 12.0!)
        Me.LabelTempMax.ForeColor = System.Drawing.Color.Gray
        Me.LabelTempMax.Location = New System.Drawing.Point(83, 56)
        Me.LabelTempMax.Name = "LabelTempMax"
        Me.LabelTempMax.Size = New System.Drawing.Size(50, 21)
        Me.LabelTempMax.TabIndex = 10
        Me.LabelTempMax.Text = "60 °C"
        '
        'LabelTemperature
        '
        Me.LabelTemperature.AutoSize = True
        Me.LabelTemperature.Font = New System.Drawing.Font("Segoe UI Black", 20.0!)
        Me.LabelTemperature.ForeColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(153, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.LabelTemperature.Location = New System.Drawing.Point(86, 129)
        Me.LabelTemperature.Name = "LabelTemperature"
        Me.LabelTemperature.Size = New System.Drawing.Size(125, 37)
        Me.LabelTemperature.TabIndex = 9
        Me.LabelTemperature.Text = "00.00 °C"
        '
        'VProgressbarTemperature
        '
        Me.VProgressbarTemperature.BorderColor = System.Drawing.Color.Black
        Me.VProgressbarTemperature.ColorStyle = Guna.UI.WinForms.ColorStyle.[Default]
        Me.VProgressbarTemperature.IdleColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        Me.VProgressbarTemperature.Location = New System.Drawing.Point(50, 56)
        Me.VProgressbarTemperature.Name = "VProgressbarTemperature"
        Me.VProgressbarTemperature.ProgressMaxColor = System.Drawing.Color.Red
        Me.VProgressbarTemperature.ProgressMinColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(153, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.VProgressbarTemperature.Size = New System.Drawing.Size(30, 188)
        Me.VProgressbarTemperature.TabIndex = 8
        Me.VProgressbarTemperature.Value = 50
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Segoe UI Black", 14.0!)
        Me.Label2.ForeColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(153, Byte), Integer), CType(CType(0, Byte), Integer))
        Me.Label2.Location = New System.Drawing.Point(63, 16)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(134, 25)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "Temperature"
        '
        'Chart1
        '
        Me.Chart1.BorderlineDashStyle = System.Windows.Forms.DataVisualization.Charting.ChartDashStyle.Solid
        ChartArea1.AxisX.LabelStyle.ForeColor = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        ChartArea1.AxisX.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea1.AxisX.MajorGrid.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea1.AxisX.MajorTickMark.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea1.AxisX.MinorGrid.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea1.AxisX.MinorTickMark.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea1.AxisX2.LabelStyle.ForeColor = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        ChartArea1.AxisY.LabelStyle.ForeColor = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        ChartArea1.AxisY.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea1.AxisY.MajorGrid.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea1.AxisY.MajorTickMark.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea1.BorderColor = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        ChartArea1.Name = "ChartArea1"
        Me.Chart1.ChartAreas.Add(ChartArea1)
        Legend1.Font = New System.Drawing.Font("Segoe UI Semibold", 12.0!)
        Legend1.ForeColor = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        Legend1.IsTextAutoFit = False
        Legend1.Name = "Legend1"
        Me.Chart1.Legends.Add(Legend1)
        Me.Chart1.Location = New System.Drawing.Point(557, 12)
        Me.Chart1.Name = "Chart1"
        Series1.BorderWidth = 3
        Series1.ChartArea = "ChartArea1"
        Series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline
        Series1.Color = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        Series1.Legend = "Legend1"
        Series1.Name = "Humidity      "
        Me.Chart1.Series.Add(Series1)
        Me.Chart1.Size = New System.Drawing.Size(641, 200)
        Me.Chart1.TabIndex = 10
        Me.Chart1.Text = "Chart1"
        '
        'Chart2
        '
        Me.Chart2.BorderlineDashStyle = System.Windows.Forms.DataVisualization.Charting.ChartDashStyle.Solid
        Me.Chart2.BorderlineWidth = 2
        ChartArea2.AxisX.LabelStyle.ForeColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(153, Byte), Integer), CType(CType(0, Byte), Integer))
        ChartArea2.AxisX.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea2.AxisX.MajorGrid.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea2.AxisX.MajorTickMark.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea2.AxisX.MinorGrid.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea2.AxisX.MinorTickMark.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea2.AxisX2.LabelStyle.ForeColor = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        ChartArea2.AxisY.LabelStyle.ForeColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(153, Byte), Integer), CType(CType(0, Byte), Integer))
        ChartArea2.AxisY.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea2.AxisY.MajorGrid.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea2.AxisY.MajorTickMark.LineColor = System.Drawing.Color.FromArgb(CType(CType(237, Byte), Integer), CType(CType(235, Byte), Integer), CType(CType(235, Byte), Integer))
        ChartArea2.BorderColor = System.Drawing.Color.FromArgb(CType(CType(96, Byte), Integer), CType(CType(180, Byte), Integer), CType(CType(249, Byte), Integer))
        ChartArea2.Name = "ChartArea1"
        Me.Chart2.ChartAreas.Add(ChartArea2)
        Legend2.Font = New System.Drawing.Font("Segoe UI Semibold", 12.0!)
        Legend2.ForeColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(153, Byte), Integer), CType(CType(0, Byte), Integer))
        Legend2.IsTextAutoFit = False
        Legend2.Name = "Legend1"
        Me.Chart2.Legends.Add(Legend2)
        Me.Chart2.Location = New System.Drawing.Point(557, 224)
        Me.Chart2.Name = "Chart2"
        Series2.BorderWidth = 3
        Series2.ChartArea = "ChartArea1"
        Series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline
        Series2.Color = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(153, Byte), Integer), CType(CType(0, Byte), Integer))
        Series2.Legend = "Legend1"
        Series2.Name = "Temperature"
        Me.Chart2.Series.Add(Series2)
        Me.Chart2.Size = New System.Drawing.Size(641, 200)
        Me.Chart2.TabIndex = 11
        Me.Chart2.Text = "Chart2"
        '
        'PictureBox2
        '
        Me.PictureBox2.BackColor = System.Drawing.Color.White
        Me.PictureBox2.Image = Global.Activity_3___DHT11_Sensor.My.Resources.Resources.temperature_sensitive_60px
        Me.PictureBox2.Location = New System.Drawing.Point(1064, 269)
        Me.PictureBox2.Name = "PictureBox2"
        Me.PictureBox2.Size = New System.Drawing.Size(80, 80)
        Me.PictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox2.TabIndex = 13
        Me.PictureBox2.TabStop = False
        '
        'PictureBox1
        '
        Me.PictureBox1.BackColor = System.Drawing.Color.White
        Me.PictureBox1.Image = Global.Activity_3___DHT11_Sensor.My.Resources.Resources.dew_point_100px
        Me.PictureBox1.Location = New System.Drawing.Point(1064, 54)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(80, 80)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 12
        Me.PictureBox1.TabStop = False
        '
        'LabelStatus
        '
        Me.LabelStatus.AutoSize = True
        Me.LabelStatus.Font = New System.Drawing.Font("Segoe UI Black", 14.0!)
        Me.LabelStatus.ForeColor = System.Drawing.Color.White
        Me.LabelStatus.Location = New System.Drawing.Point(12, 434)
        Me.LabelStatus.Name = "LabelStatus"
        Me.LabelStatus.Size = New System.Drawing.Size(207, 25)
        Me.LabelStatus.TabIndex = 14
        Me.LabelStatus.Text = "Status: Disconnected"
        '
        'PictureBoxStatusConnection
        '
        Me.PictureBoxStatusConnection.BackColor = System.Drawing.Color.Red
        Me.PictureBoxStatusConnection.Location = New System.Drawing.Point(219, 437)
        Me.PictureBoxStatusConnection.Name = "PictureBoxStatusConnection"
        Me.PictureBoxStatusConnection.Size = New System.Drawing.Size(20, 20)
        Me.PictureBoxStatusConnection.TabIndex = 15
        Me.PictureBoxStatusConnection.TabStop = False
        '
        'TimerSerial
        '
        Me.TimerSerial.Interval = 2000
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.Black
        Me.ClientSize = New System.Drawing.Size(1210, 468)
        Me.Controls.Add(Me.PictureBoxStatusConnection)
        Me.Controls.Add(Me.LabelStatus)
        Me.Controls.Add(Me.PictureBox2)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.Chart2)
        Me.Controls.Add(Me.Chart1)
        Me.Controls.Add(Me.PanelTemperature)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.PanelConnection)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "Form1"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "VB NET DHT11 Sensor"
        Me.PanelConnection.ResumeLayout(False)
        Me.PanelConnection.PerformLayout()
        Me.Panel1.ResumeLayout(False)
        Me.Panel1.PerformLayout()
        Me.PanelTemperature.ResumeLayout(False)
        Me.PanelTemperature.PerformLayout()
        CType(Me.Chart1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Chart2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBoxStatusConnection, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents PanelConnection As Panel
    Friend WithEvents ComboBoxPort As Guna.UI.WinForms.GunaComboBox
    Friend WithEvents LabelConnectionTitle As Label
    Friend WithEvents ButtonScanPort As Bunifu.UI.WinForms.BunifuButton.BunifuButton
    Friend WithEvents ButtonConnect As Bunifu.UI.WinForms.BunifuButton.BunifuButton
    Friend WithEvents ComboBaudRate As Guna.UI.WinForms.GunaComboBox
    Friend WithEvents LabelBaudRate As Label
    Friend WithEvents Panel1 As Panel
    Friend WithEvents CircleProgressbarHumidity As Bunifu.Framework.UI.BunifuCircleProgressbar
    Friend WithEvents Label1 As Label
    Friend WithEvents PanelTemperature As Panel
    Friend WithEvents LabelTempMin As Label
    Friend WithEvents LabelTempMax As Label
    Friend WithEvents LabelTemperature As Label
    Friend WithEvents VProgressbarTemperature As Guna.UI.WinForms.GunaVProgressBar
    Friend WithEvents Label2 As Label
    Friend WithEvents Chart1 As DataVisualization.Charting.Chart
    Friend WithEvents Chart2 As DataVisualization.Charting.Chart
    Friend WithEvents PictureBox1 As PictureBox
    Friend WithEvents PictureBox2 As PictureBox
    Friend WithEvents LabelStatus As Label
    Friend WithEvents PictureBoxStatusConnection As PictureBox
    Friend WithEvents SerialPort1 As IO.Ports.SerialPort
    Friend WithEvents ButtonDisconnect As Bunifu.UI.WinForms.BunifuButton.BunifuButton
    Friend WithEvents TimerSerial As Timer
End Class
