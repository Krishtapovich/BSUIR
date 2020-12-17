object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1060#1080#1075#1091#1088#1099
  ClientHeight = 393
  ClientWidth = 766
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnKeyDown = FormKeyDown
  OnMouseDown = FormMouseDown
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  PixelsPerInch = 96
  TextHeight = 13
  object Label18: TLabel
    Left = 591
    Top = 238
    Width = 3
    Height = 13
  end
  object GroupBox1: TGroupBox
    Left = 430
    Top = 8
    Width = 332
    Height = 168
    Caption = #1060#1080#1075#1091#1088#1099
    TabOrder = 0
    object Label7: TLabel
      Left = 120
      Top = 25
      Width = 10
      Height = 13
      Caption = 'a:'
    end
    object Label8: TLabel
      Left = 191
      Top = 25
      Width = 10
      Height = 13
      Caption = 'b:'
    end
    object Label9: TLabel
      Left = 120
      Top = 52
      Width = 10
      Height = 13
      Caption = 'a:'
    end
    object Label13: TLabel
      Left = 114
      Top = 106
      Width = 17
      Height = 13
      Caption = 'Ra:'
    end
    object Label14: TLabel
      Left = 185
      Top = 105
      Width = 17
      Height = 13
      Caption = 'Rb:'
    end
    object Label15: TLabel
      Left = 120
      Top = 137
      Width = 11
      Height = 13
      Caption = 'R:'
    end
    object Label10: TLabel
      Left = 120
      Top = 80
      Width = 10
      Height = 13
      Caption = 'a:'
    end
    object RadioButton1: TRadioButton
      Left = 17
      Top = 24
      Width = 97
      Height = 17
      Caption = #1055#1088#1103#1084#1086#1091#1075#1086#1083#1100#1085#1080#1082
      Ctl3D = True
      ParentCtl3D = False
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 18
      Top = 51
      Width = 65
      Height = 17
      Caption = #1050#1074#1072#1076#1088#1072#1090
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object RadioButton3: TRadioButton
      Left = 18
      Top = 77
      Width = 81
      Height = 17
      Caption = #1058#1088#1077#1091#1075#1086#1083#1100#1085#1080#1082
      TabOrder = 2
      OnClick = RadioButton3Click
    end
    object RadioButton4: TRadioButton
      Left = 18
      Top = 105
      Width = 57
      Height = 17
      Caption = #1069#1083#1083#1080#1087#1089
      TabOrder = 3
      OnClick = RadioButton4Click
    end
    object RadioButton5: TRadioButton
      Left = 18
      Top = 136
      Width = 41
      Height = 17
      Caption = #1050#1088#1091#1075
      TabOrder = 4
      OnClick = RadioButton5Click
    end
    object Edit1: TEdit
      Left = 135
      Top = 22
      Width = 42
      Height = 21
      Enabled = False
      HideSelection = False
      TabOrder = 5
    end
    object Edit2: TEdit
      Left = 207
      Top = 22
      Width = 42
      Height = 21
      DoubleBuffered = True
      Enabled = False
      ParentDoubleBuffered = False
      TabOrder = 6
    end
    object Edit3: TEdit
      Left = 136
      Top = 49
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 7
    end
    object Edit7: TEdit
      Left = 137
      Top = 102
      Width = 40
      Height = 21
      Enabled = False
      TabOrder = 8
    end
    object Edit8: TEdit
      Left = 208
      Top = 102
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 9
    end
    object Edit9: TEdit
      Left = 137
      Top = 134
      Width = 40
      Height = 21
      Enabled = False
      TabOrder = 10
    end
    object Edit4: TEdit
      Left = 136
      Top = 75
      Width = 41
      Height = 21
      Enabled = False
      TabOrder = 11
    end
  end
  object GroupBox2: TGroupBox
    Left = 430
    Top = 182
    Width = 332
    Height = 155
    Caption = #1044#1077#1081#1089#1090#1074#1080#1103' '#1089' '#1092#1080#1075#1091#1088#1072#1084#1080
    TabOrder = 1
    object Label19: TLabel
      Left = 121
      Top = 53
      Width = 23
      Height = 13
      Caption = 'Deg:'
    end
    object Label20: TLabel
      Left = 16
      Top = 88
      Width = 262
      Height = 13
      Caption = #1044#1083#1103' '#1084#1072#1089#1096#1090#1072#1073#1080#1088#1086#1074#1072#1085#1080#1103' '#1080#1089#1087#1086#1083#1100#1079#1091#1081#1090#1077' '#1082#1086#1083#1077#1089#1080#1082#1086' '#1084#1099#1096#1080
    end
    object Label21: TLabel
      Left = 133
      Top = 119
      Width = 10
      Height = 13
      Caption = 'X:'
    end
    object Label22: TLabel
      Left = 215
      Top = 119
      Width = 10
      Height = 13
      Caption = 'Y:'
    end
    object Label16: TLabel
      Left = 13
      Top = 23
      Width = 213
      Height = 13
      Caption = #1044#1083#1103' '#1087#1077#1088#1077#1084#1077#1097#1077#1085#1080#1103' '#1080#1089#1087#1086#1083#1100#1079#1091#1081#1090#1077' W, A, S, D'
    end
    object RadioButton8: TRadioButton
      Left = 13
      Top = 53
      Width = 60
      Height = 17
      Caption = #1055#1086#1074#1086#1088#1086#1090
      TabOrder = 0
      OnClick = RadioButton8Click
    end
    object RadioButton6: TRadioButton
      Left = 13
      Top = 117
      Width = 108
      Height = 17
      Caption = #1050'-'#1090#1099' '#1094#1077#1085#1090#1088#1072' '#1084#1072#1089#1089
      TabOrder = 1
      OnClick = RadioButton6Click
    end
    object Edit12: TEdit
      Left = 150
      Top = 50
      Width = 49
      Height = 21
      Enabled = False
      TabOrder = 2
    end
    object Edit14: TEdit
      Left = 149
      Top = 117
      Width = 52
      Height = 21
      Enabled = False
      TabOrder = 3
    end
    object Edit15: TEdit
      Left = 227
      Top = 117
      Width = 52
      Height = 21
      Enabled = False
      TabOrder = 4
    end
  end
  object Panel1: TPanel
    Left = 313
    Top = 343
    Width = 449
    Height = 49
    TabOrder = 2
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 51
      Height = 13
      Caption = #1055#1083#1086#1097#1072#1076#1100':'
    end
    object Label2: TLabel
      Left = 75
      Top = 16
      Width = 3
      Height = 13
    end
    object Label3: TLabel
      Left = 160
      Top = 16
      Width = 53
      Height = 13
      Caption = #1055#1077#1088#1080#1084#1077#1090#1088':'
    end
    object Label4: TLabel
      Left = 219
      Top = 16
      Width = 3
      Height = 13
    end
    object Label5: TLabel
      Left = 304
      Top = 16
      Width = 61
      Height = 13
      Caption = #1062#1077#1085#1090#1088' '#1084#1072#1089#1089':'
    end
    object Label6: TLabel
      Left = 371
      Top = 16
      Width = 3
      Height = 13
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 50
    OnTimer = Timer1Timer
    Left = 256
    Top = 344
  end
  object Timer2: TTimer
    Interval = 1
    OnTimer = Timer2Timer
    Left = 200
    Top = 344
  end
end
