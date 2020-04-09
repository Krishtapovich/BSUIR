object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = 'Airplane'
  ClientHeight = 336
  ClientWidth = 724
  Color = clHotLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Road: TShape
    Left = 0
    Top = 248
    Width = 725
    Height = 89
    Brush.Color = clGrayText
    Pen.Style = psClear
  end
  object Shape1: TShape
    Left = 24
    Top = 280
    Width = 49
    Height = 17
  end
  object Shape2: TShape
    Left = 96
    Top = 280
    Width = 49
    Height = 17
  end
  object Shape3: TShape
    Left = 168
    Top = 280
    Width = 49
    Height = 17
  end
  object Shape4: TShape
    Left = 240
    Top = 280
    Width = 49
    Height = 17
  end
  object Shape5: TShape
    Left = 312
    Top = 280
    Width = 49
    Height = 17
  end
  object Shape6: TShape
    Left = 384
    Top = 280
    Width = 49
    Height = 17
  end
  object Shape7: TShape
    Left = 456
    Top = 280
    Width = 49
    Height = 17
  end
  object Shape8: TShape
    Left = 528
    Top = 280
    Width = 49
    Height = 17
  end
  object Shape9: TShape
    Left = 600
    Top = 280
    Width = 49
    Height = 17
  end
  object Shape10: TShape
    Left = 672
    Top = 280
    Width = 49
    Height = 17
  end
  object Shape11: TShape
    Left = 192
    Top = 32
    Width = 49
    Height = 49
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape12: TShape
    Left = 247
    Top = 32
    Width = 50
    Height = 57
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape13: TShape
    Left = 216
    Top = 8
    Width = 65
    Height = 57
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape14: TShape
    Left = 216
    Top = 40
    Width = 49
    Height = 49
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape15: TShape
    Left = 456
    Top = 88
    Width = 49
    Height = 49
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape16: TShape
    Left = 456
    Top = 56
    Width = 65
    Height = 57
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape17: TShape
    Left = 487
    Top = 80
    Width = 50
    Height = 57
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape18: TShape
    Left = 432
    Top = 80
    Width = 49
    Height = 49
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape19: TShape
    Left = 88
    Top = 104
    Width = 49
    Height = 49
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape20: TShape
    Left = 88
    Top = 72
    Width = 65
    Height = 57
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape21: TShape
    Left = 119
    Top = 96
    Width = 50
    Height = 57
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape22: TShape
    Left = 64
    Top = 96
    Width = 49
    Height = 49
    Brush.Color = clCream
    Pen.Color = clWhite
    Shape = stCircle
  end
  object Shape23: TShape
    Left = -16
    Top = -8
    Width = 65
    Height = 65
    Brush.Color = clYellow
    Pen.Color = clYellow
    Shape = stCircle
  end
  object Button2: TButton
    Left = 600
    Top = 32
    Width = 100
    Height = 25
    Cursor = crHandPoint
    Caption = #1042#1099#1087#1091#1089#1090#1080#1090#1100' '#1096#1072#1089#1089#1080
    TabOrder = 0
    OnClick = Button2Click
  end
  object Timer1: TTimer
    Interval = 50
    OnTimer = Timer1Timer
    Left = 664
    Top = 72
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 50
    OnTimer = Timer2Timer
    Left = 672
    Top = 168
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 125
    OnTimer = Timer3Timer
    Left = 640
    Top = 128
  end
end
