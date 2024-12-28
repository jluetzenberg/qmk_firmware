# JL Ergo 36

This is a 36-key monoblock keyboard with tent and tilt. It uses a 3x5 matrix per side, plus
3 thumb keys. In addition, there is a centrally-located cirque glidepoint running in SPI and
a 5-way switch functioning as the mouse buttons

```json
{
"notes": [
    {
        "feature": "USB",
        "pins": [ {"pin": "40", "name": "VBUS - from usb, power" } ]
    },
    {
        "feature": "Trackpad",
        "pins": [
            {"pin": "38", "name": "ground", "color": "white solid core, dp white" },
            {"pin": "36", "name": "3v3 out, to trackpad", "color": "red solid core, dp black" },
            {"pin": "02", "name": "MISO", "color": "DP - grey" },
            {"pin": "05", "name": "MOSI", "color": "DP - blue" },
            {"pin": "01", "name": "SCK", "color": "DP - brown" },
            {"pin": "04", "name": "SS", "color": "DP - red" }
        ]
    },
    {
        "feature": "COLUMNS",
        "pins": [
            {"pin": "26", "name": "col 01", "color": "stranded brown" },
            {"pin": "25", "name": "col 02", "color": "stranded green" },
            {"pin": "24", "name": "col 03", "color": "stranded blue" },
            {"pin": "22", "name": "col 04", "color": "stranded orange" },
            {"pin": "21", "name": "col 05", "color": "stranded white-orange" },
            {"pin": "20", "name": "col 06", "color": "stranded white-orange" },
            {"pin": "19", "name": "col 07", "color": "stranded orange" },
            {"pin": "17", "name": "col 08", "color": "stranded blue" },
            {"pin": "16", "name": "col 09", "color": "stranded green" },
            {"pin": "15", "name": "col 10", "color": "stranded brown" }
        ]
    },
    {
        "feature": "ROWS",
        "pins": [
            {"pin": "14", "name": "row 01, top", "color": "stranded brown" },
            {"pin": "12", "name": "row 02, mid", "color": "stranded green" },
            {"pin": "11", "name": "row 03, bottom", "color": "stranded blue" },
            {"pin": "27", "name": "row 04, thumbs", "color": "stranded orange" },
            {"pin": "29", "name": "row 05, mouse keys", "color": "stranded brown" }
        ]
    }
],
}
```

# Dilemma v2 (3x5+3 assembled)

This keyboard is an updated version of the [3x5+2 Dilemma](../3x5_2/).

The Dilemma v2 is available at [bastardkb.com](https://bastardkb.com).
