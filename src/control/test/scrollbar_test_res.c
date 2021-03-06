/*
** $Id: scrollbar_test_res.c,v 2.2 2008-01-26 02:02:03 hejian Exp $
**
** scrollbar_test_res.c: The scrollbar control test's dialog box templates.
**
** Copyright (C) 2001 ~ 2002 Wei Yongming.
** Copyright (C) 2003 ~ 2008 Feynman Software.
*/

#include <stdio.h>
#include <stdlib.h>

#include <minigui/common.h>
#include <minigui/minigui.h>
#include <minigui/gdi.h>
#include <minigui/window.h>
#include <minigui/control.h>

#include "resource.h"

// 初始化进程对话框
DLGTEMPLATE DlgInitProgress =
{
    WS_BORDER | WS_CAPTION, 
    WS_EX_NONE,
    120, 150, 420, 130, 
    "滚动条风格组合测试及消息和通知码的测试",
    0, 0,
    6, NULL,
    0
};

CTRLDATA CtrlInitProgress [] =
{ 
    {
        "static",
        WS_VISIBLE | SS_SIMPLE,
        60, 10, 80, 16, 
        IDC_PROMPTINFO, 
        "风格组合",
        0
    },
    {
        "edit",
        WS_VISIBLE|WS_BORDER,
        10, 40, 540, 20,
        IDC_PROGRESS,
        NULL,
        0,
        ES_READONLY
    },
    {
        "static",
        WS_VISIBLE | SS_SIMPLE,
        30, 70, 380, 16, 
        IDC_PROMPTINFO2, 
        "风格组合的测试结果以及消息和通知码的测试结果",
        0
    },
    {
        CTRL_MLEDIT,
        WS_VISIBLE|WS_BORDER,
        10,90, 380, 190,
        IDC_PROGRESS2,
        NULL,
        0,
        ES_READONLY|ES_MULTILINE|ES_AUTOWRAP
    },
    {
        "button",
        WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON, 
        170, 290, 150, 25,
        IDOK, 
        "下一个风格组合",
        0
    },
    {
        "button",
        WS_TABSTOP | WS_VISIBLE | BS_DEFPUSHBUTTON, 
        370, 290, 220, 25,
        IDC_SCROLLBAR_MESSAGE_BUTTON, 
        "消息及通知码测试",
        0
    }

};


DLGTEMPLATE DlgStartupMode =
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    120, 100, 400, 334,
    "绘制效率测试",
    0, 0,
    1, NULL,
    0
};


CTRLDATA CtrlStartupMode[] =
{ 
    {
        "button",
        WS_VISIBLE | BS_DEFPUSHBUTTON | WS_TABSTOP | WS_GROUP,
        272, 282, 95, 28,
        IDOK, 
        "创建控件",
        0
    }
};


DLGTEMPLATE DlgStructParams = 
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    10, 80, 520, 320,
    "内存泄漏测试",
    0, 0,
    3, NULL
};

CTRLDATA CtrlStructParams[] = 
{
    {
        "static",
        WS_VISIBLE | SS_RIGHT,
        4, 14, 160, 22, 
        IDC_STATIC, 
        "内存泄漏测试内容",
        0
    },
    {
        CTRL_MLEDIT,
        WS_VISIBLE | WS_BORDER | WS_TABSTOP,
        34, 40, 503, 222,
        IDC_EDIT1,
        NULL,
        0,
        ES_READONLY|ES_MULTILINE
    },
    {
        "button",
        WS_VISIBLE | BS_DEFPUSHBUTTON | WS_TABSTOP,
        300, 280, 100, 28,
        IDOK, 
        "开始测试",
        0
    }
};


DLGTEMPLATE DlgPassword = 
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    70, 80, 460, 158,
    "窗口刷新测试",
    0, 0,
    2, NULL,
    0
};
     
CTRLDATA CtrlPassword [] = 
{
    {
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP, 
        272, 282, 100, 28, 
        IDOK, 
        "开始测试",
        0 
    },
    {
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP, 
        390, 282, 100, 28, 
        IDCANCEL, 
        "退出",
        0 
    }
};
 
DLGTEMPLATE Dlgutmost = 
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    10, 80, 460, 158,
    "极限值测试",
    0, 0,
    3, NULL,
    0
};
     
CTRLDATA Ctrlutmost [] = 
{
    {
        "static",
        WS_VISIBLE | SS_RIGHT,
        4, 10, 350, 18,
        IDC_STATIC, 
        "下面是极限值测试的测试内容及测试结果",
        0
    },
    {
        CTRL_MLEDIT,
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_PASSWORD | WS_TABSTOP, 
        20, 38, 600, 250, 
        IDC_UTMOSTCONTENT, 
        NULL,
        0,
        ES_READONLY
    },
    {
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        280, 300, 100, 22, 
        IDC_UTMOSTSTART, 
        "开始测试",
        0
    }
};


DLGTEMPLATE DlgPropertySheet = 
{
    WS_BORDER | WS_CAPTION,
    WS_EX_NONE,
    20, 20, 580+155, 450,
    "Scrollbar control test",
    0, 0,
    2, NULL,
    0
};

CTRLDATA CtrlPropertySheet [] = 
{
    {
        CTRL_PROPSHEET,
        WS_VISIBLE | WS_TABSTOP | PSS_COMPACTTAB,
        10, 10, 560+155, 360,
        IDC_PROPSHEET, 
        "Property sheet control",
        0
    },
    /*{
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP, 
        200, 380, 100, 28, 
        IDC_APPLY, 
        "应用",
        0 
    },
    {
        "button",
        WS_VISIBLE | BS_DEFPUSHBUTTON | WS_TABSTOP, 
        340, 380, 100, 28, 
        IDOK, 
        "确定",
        0 
    },*/
    {
        "button",
        WS_VISIBLE | BS_PUSHBUTTON | WS_TABSTOP,
        460, 380, 100, 28, 
        IDCANCEL, 
        "退出", 
        0
    }
};

