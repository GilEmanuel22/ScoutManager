
// ProjectDlg.h : header file
//

#pragma once

#include "Goalkeeper.h"
#include "Manager.h"
#include "Person.h"
#include "Midfielder.h"
#include "Deffender.h"
#include "Striker.h"
#include "Player.h"
#include"afx.h"
#include <memory>
//#include "CINKPICTURE5.h"
//template <typename T>


// CProjectDlg dialog
class CProjectDlg : public CDialogEx
{
private:
	std::unique_ptr<Gdiplus::Bitmap> m_backgroundImgae;
// Construction
public:
	CProjectDlg(CWnd* pParent = nullptr);	// standard constructor


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//template <typename NAME>

	afx_msg void OnBnClickedbtnadd();
	afx_msg void OnBnClickedbtnplayer();
	afx_msg void OnBnClickedbtncoach();
	afx_msg void OnEnChangebtneditlongshoot3();
	afx_msg void OnBnClickedbtnradiostriker();
	afx_msg void OnEnChangebtneditpower();
	string  getsetname();
	int getsetage();
	int getsetspeed();
	int getsetjump();
	int getsetstamina();

	CTypedPtrArray < CObArray, Person*> workers;

	int GetAgeFormController();
	int getreflexfromcontroller();
	int getoneononefromcontroller();
	int getspeedfromcontroller();
	int getjumpfromcontroller();
	int getstaminafromcontroller();
	int getleadringfromcontroller();
	int getthrowingfromcontroller();
	int getHeadingfromcontroller();
	int getpassingfromcontroller();
	int getsavingfromcontroller();
	int getTacklesfromcontroller();
	int getbravefromcontroller();
	int getLongshoot2fromcontroller();
	int getLongPassfromcontroller();
	int getfinishfromcontroller();
	int Shoot();
	int Movement();
	int Years_career();
	int Game_mangement();
	int Tactics();
	int Motivation();







	afx_msg void OnEnChangebtneditname();
	CString m_name;
	afx_msg void OnBnClickedbtnclear();
	afx_msg void OnBnClickedbtndelete();

	void UpdateList();
	afx_msg void OnBnClickedbtnupdate();
	CString GetNameFormController();
	afx_msg void OnLbnSelchangelistboxworkers();
	afx_msg void OnEnChangebtneditreflex();
	afx_msg void OnEnChangebtneditage();
	afx_msg void OnEnChangebtneditpower3();
	int getpowerfromcontroller();
	void Serialize(CArchive& ar)override;

	afx_msg void OnBnClickedid();
	afx_msg void OnBnClickedload();
	//CINKPICTURE3 fm;
	//CINKPICTURE5 pici;
	
};
