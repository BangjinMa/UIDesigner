// stdafx.cpp : 只包括标准包含文件的源文件
// UIDesigner.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

CMainFrame* g_pMainFrame = NULL;
CToolBoxWnd* g_pToolBoxWnd = NULL;
CPropertiesWnd* g_pPropertiesWnd = NULL;
CFileView* g_pFileView = NULL;
CClassView* g_pClassView = NULL;
CResourceViewBar* g_pResourceView = NULL;
CHookAPI g_pHookAPI;

int gGetUIClass(LPCTSTR pstrClass)
{
	int nClass = classPointer;
	if( _tcscmp(pstrClass, _T("FormUI")) == 0 )                   nClass=classWindow;
	else if( _tcscmp(pstrClass, DUI_CTR_EDIT) == 0 )              nClass=classEdit;
	else if( _tcscmp(pstrClass, DUI_CTR_LIST) == 0 )              nClass=classList;
	else if( _tcscmp(pstrClass, DUI_CTR_TEXT) == 0 )              nClass=classText;
	else if( _tcscmp(pstrClass, DUI_CTR_COMBO) == 0 )                  nClass=classCombo;
	else if( _tcscmp(pstrClass, DUI_CTR_LABEL) == 0 )             nClass=classLabel;
	else if( _tcscmp(pstrClass, DUI_CTR_BUTTON) == 0 )                 nClass=classButton;
	else if( _tcscmp(pstrClass, DUI_CTR_OPTION) == 0 )            nClass=classOption;
	else if( _tcscmp(pstrClass, DUI_CTR_SLIDER) == 0 )            nClass=classSlider;
	else if( _tcscmp(pstrClass, DUI_CTR_CONTROL) == 0 )                nClass=classControl;
	else if( _tcscmp(pstrClass, DUI_CTR_ACTIVEX) == 0 )           nClass=classActiveX;
	else if( _tcscmp(pstrClass, DUI_CTR_PROGRESS) == 0 )               nClass=classProgress;
	else if( _tcscmp(pstrClass, DUI_CTR_CONTAINER) == 0 )              nClass=classContainer;
	else if( _tcscmp(pstrClass, DUI_CTR_TABLAYOUT) == 0 )         nClass=classTabLayout;
	else if( _tcscmp(pstrClass, DUI_CTR_LISTHEADERITEM) == 0 )             nClass=classListHeader;
	else if( _tcscmp(pstrClass, _T("TileLayoutUI")) == 0 )        nClass=classTileLayout;
	else if (_tcscmp(pstrClass, _T("VScrollBarUI")) == 0 )			nClass=classScrollBar;
	else if (_tcscmp(pstrClass, DUI_CTR_SCROLLBAR) == 0 )			nClass=classScrollBar;
	else if( _tcscmp(pstrClass, _T("VerticalLayoutUI")) == 0 )         nClass=classVerticalLayout;
	else if( _tcscmp(pstrClass, DUI_CTR_LISTHBOXELEMENT) == 0 )    nClass=classListHeaderItem;
	else if( _tcscmp(pstrClass, DUI_CTR_LISTTEXTELEMENT) == 0 )        nClass=classListTextElement;
	else if( _tcscmp(pstrClass, DUI_CTR_HORIZONTALLAYOUT) == 0 )       nClass=classHorizontalLayout;
	else if( _tcscmp(pstrClass, DUI_CTR_LISTLABELELEMENT) == 0 )  nClass=classListLabelElement;
	else if( _tcscmp(pstrClass, _T("ListContainerElementUI")) == 0 )   nClass=classListContainerElement;

	return nClass;
}
int gGetUIClass(CControlUI* pControl)
{
	if(pControl==NULL)
		return classPointer;

	return gGetUIClass(pControl->GetClass());
}