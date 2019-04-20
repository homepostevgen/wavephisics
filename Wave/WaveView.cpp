// WaveView.cpp : implementation of the CWaveView class
//

#include "stdafx.h"
#include "Wave.h"

#include "WaveDoc.h"
#include "WaveView.h"
#include "windows.h"
#include "iostream.h"
#include "fstream"
#include "math.h"
#include "mmsystem.h"
#include "Processing.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWaveView

IMPLEMENT_DYNCREATE(CWaveView, CView)

BEGIN_MESSAGE_MAP(CWaveView, CView)
	//{{AFX_MSG_MAP(CWaveView)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWaveView construction/destruction

CWaveView::CWaveView()
{
	// TODO: add construction code here

}

CWaveView::~CWaveView()
{
}

BOOL CWaveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CWaveView drawing

void CWaveView::OnDraw(CDC* pDC)
{
	int n=200;
	byte buffer[2048];
	DWORD sample;
	HANDLE hFile;
	hFile=CreateFile("Untitled-4.wav", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD dwBytesRead; 
	ReadFile(hFile, &buffer, sizeof(buffer), &dwBytesRead, (LPOVERLAPPED)NULL);
	CloseHandle(hFile);
	//PlaySound("Untitled.wav",NULL,SND_FILENAME | SND_ASYNC);
	/*ifstream File("Untitled.wav");	//открываем файлы для записи данных
	if (!File)sample=256;
	else sample=16;
	for(int j=0;j<n;j++)
		{
			//File>>sample;
		//	if (j>208)
			File>>buffer[j];
		}
	File>>sample;
	File.close();*/
	
	
	for(int i=0;i<2048;i++)
	{
		pDC->LineTo(i-103,400+buffer[i]*0.5*3-128*3);
	}
	
	CProcessing p;


	
	
	
	
	CWaveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CWaveView printing

BOOL CWaveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CWaveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CWaveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CWaveView diagnostics

#ifdef _DEBUG
void CWaveView::AssertValid() const
{
	CView::AssertValid();
}

void CWaveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWaveDoc* CWaveView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWaveDoc)));
	return (CWaveDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWaveView message handlers

void CWaveView::OnLButtonDown(UINT nFlags, CPoint point) 
{
		//PlaySound("Untitled.wav",NULL,SND_FILENAME | SND_ASYNC);
	
		// TODO: Add your message handler code here and/or call default
	
	CView::OnLButtonDown(nFlags, point);
}
