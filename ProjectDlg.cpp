
// ProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Project.h"
#include "ProjectDlg.h"
#include "afxdialogex.h"
#include <sstream>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
	//
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, btnEditName, m_name);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProjectDlg dialog



CProjectDlg::CProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECT_DIALOG, pParent)
	, m_name(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, btnEditName, m_name);
	//DDX_Control(pDX, IDC_INKPICTURE3, fm);
	//DDX_Control(pDX, IDC_INKPICTURE5, pici);
}

BEGIN_MESSAGE_MAP(CProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(btnAdd, &CProjectDlg::OnBnClickedbtnadd)
	ON_BN_CLICKED(btnPlayer, &CProjectDlg::OnBnClickedbtnplayer)
	ON_BN_CLICKED(btnCoach, &CProjectDlg::OnBnClickedbtncoach)
	ON_BN_CLICKED(btnRadioStriker, &CProjectDlg::OnBnClickedbtnradiostriker)
	ON_EN_CHANGE(btnEditName, &CProjectDlg::OnEnChangebtneditname)
	ON_BN_CLICKED(btnClear, &CProjectDlg::OnBnClickedbtnclear)
	ON_BN_CLICKED(btnDelete, &CProjectDlg::OnBnClickedbtndelete)
	ON_BN_CLICKED(btnUpdate, &CProjectDlg::OnBnClickedbtnupdate)
	ON_LBN_SELCHANGE(listBoxWorkers, &CProjectDlg::OnLbnSelchangelistboxworkers)
	ON_EN_CHANGE(btnEditReflex, &CProjectDlg::OnEnChangebtneditreflex)
	ON_EN_CHANGE(btnEditAge, &CProjectDlg::OnEnChangebtneditage)
	ON_EN_CHANGE(btnEditPower3, &CProjectDlg::OnEnChangebtneditpower3)
	ON_BN_CLICKED(save_id, &CProjectDlg::OnBnClickedid)
	ON_BN_CLICKED(ID_load, &CProjectDlg::OnBnClickedload)
END_MESSAGE_MAP()


// CProjectDlg message handlers

BOOL CProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//template <typename NAME>

void CProjectDlg::OnBnClickedbtnadd()
{
	// btnPlayer

	// btnCoach
	

	CStatic* map =(CStatic*)GetDlgItem(IDC_STATIC);
	
	Person* person = NULL;


	CButton* btnGoalKeeper = (CButton*)GetDlgItem(btnRadioGoalKeeper);
	CButton* btnDeffender = (CButton*)GetDlgItem(btnRadioDeffender);
	CButton* btnMidfielder = (CButton*)GetDlgItem(btnRadioMidfielder);
	CButton* btnStriker = (CButton*)GetDlgItem(btnRadioStriker);
	CButton* btncoach = (CButton*)GetDlgItem(btnCoach);
	CButton* btnplayer = (CButton*)GetDlgItem(btnPlayer);
	btnGoalKeeper->EnableWindow(false);
	btnDeffender->EnableWindow(false);
	btnMidfielder->EnableWindow(false);
	btnStriker->EnableWindow(false);
	CString name = GetNameFormController();
	string NAME((CT2CA)name);
	//int time;
	
	int age = GetAgeFormController();
	if (btnplayer->GetCheck())
	{

		btnGoalKeeper->EnableWindow(true);
		btnDeffender->EnableWindow(true);
		btnMidfielder->EnableWindow(true);
		btnStriker->EnableWindow(true);

	
	
	
	   
	
		int speed = getspeedfromcontroller();
		int jump = getjumpfromcontroller();
		int stamina = getstaminafromcontroller();
		int power = getpowerfromcontroller();
		int Heading = getHeadingfromcontroller();
		int passing = getpassingfromcontroller();
		/*HBITMAP EntityImage = (HBITMAP)LoadImage(NULL, L"Avatars/" "manger.jpg", IMAGE_BITMAP, 145, 140, LR_LOADFROMFILE);
		map->SetBitmap(EntityImage);*/
		CImage ViewImage; CBitmap ViewBitmap;
		ViewImage.Load(_T("manger.jpg"));
		ViewBitmap.Attach(ViewImage.Detach());
		map->SetBitmap((HBITMAP)ViewBitmap);

		if (btnGoalKeeper->GetCheck())
		{
			int reflex = getreflexfromcontroller();
			int oneonone = getoneononefromcontroller();
			int leadring = getleadringfromcontroller();
			int throwing = getthrowingfromcontroller();
	
		
		
		

			Goalkeeper* GK = new Goalkeeper(NAME, age, speed, jump, stamina, reflex, oneonone, leadring, throwing);
			CString hap;
			double result = GK->CalulateSalary();
			CString str1;
			CString str2;
			CString str3;
			CString str4;
			CString str5;
			int time = GK->time_contract_for_player();
			
		
			str1.AppendFormat(name );
			str2.AppendFormat(_T(": Goalkeeper"));

			str3.AppendFormat(_T(", age  %d"), age);
			str4.AppendFormat(_T(", salary  %2.lf"), result);
			hap.AppendFormat(_T(", for %d years"), time);
			MessageBox(str1 + str2 + str3 + str4 + hap);
		
			person = GK;

			workers.Add(person);

			CListBox* listWorkers = (CListBox*)GetDlgItem(listBoxWorkers);
			if (result == 0)
			{
				MessageBox(_T("Sorry,he isn't include in our standard,try to practice."));
			}
			if (speed > 20 || jump > 20 || stamina > 20 || throwing > 20 || reflex > 20 || Heading > 20 || oneonone > 20 || leadring > 20)
			{
				MessageBox(_T("pleass press again,the grade is over the ability."));
			}

			//listWorkers->AddString(str);
			listWorkers->AddString(str1+str2+str3+str4+hap);
		
		}
		if (btnDeffender->GetCheck())
		{
			CString hap;
			int saving = getsavingfromcontroller();
			int Tackles = getTacklesfromcontroller();
			int brave = getbravefromcontroller();
			Deffender* player2 = new Deffender(NAME, age, speed, jump, stamina, power, Tackles, saving, brave, Heading);
			person = player2;
			workers.Add(person);

			CString str1;
			CString str2;
			CString str3;
			CString str4;
			//CString str5;
			
			str1.AppendFormat(name);
			str2.AppendFormat(_T(": Deffender"));

			str3.AppendFormat(_T(", age  %d"), age);
			double res = player2->CalulateSalary();
			
			int time = player2->time_contract_for_player();
			str4.AppendFormat(_T(", salary  %2.lf"), res);
			//str5.AppendFormat(_T("", time));
			hap.AppendFormat(_T(" , for %d years"), time);
			MessageBox(str1+str2+str3+str4+hap);
			CListBox* listWorkers = (CListBox*)GetDlgItem(listBoxWorkers);
			if (res == 0)
			{
				MessageBox(_T("Sorry,he isn't include in our standard,try to practice."));
			}
			if (speed > 20 || jump > 20 || stamina > 20 || power > 20 ||  brave > 20 || Heading >  20 || Tackles > 20 ||  saving > 20)
			{
				MessageBox(_T("pleass press again,the grade is over the ability."));
			}

			//listWorkers->AddString(str);
			listWorkers->AddString(str1 + str2 + str3 + str4+hap);
		}
		if (btnMidfielder->GetCheck())
		{
			CString hap;
			int saving = getsavingfromcontroller();
			int Tackles = getTacklesfromcontroller();
			int brave = getbravefromcontroller();
			int Longshoot = getLongshoot2fromcontroller();
			int Longpass = getLongPassfromcontroller();

			Midfielder* player3 = new Midfielder(NAME, age, speed, jump, stamina, passing, power, Longshoot, Longpass);
			person = player3;
			workers.Add(person);

			CString str1;
			CString str2;
			CString str3;
			CString str4;

			str1.AppendFormat(name);
			str2.AppendFormat(_T(", Midfielder"));

			str3.AppendFormat(_T(", age  %d"), age);
			double res = player3->CalulateSalary();
			int time = player3->time_contract_for_player();
			hap.AppendFormat(_T("for %d years"), time);
			str4.AppendFormat(_T(", salary  %2.lf , "), res);
			//MessageBox(hap);
			CListBox* listWorkers = (CListBox*)GetDlgItem(listBoxWorkers);


			//listWorkers->AddString(str);
			listWorkers->AddString(str1 + str2 + str3 + str4+hap);
	
			MessageBox(str1+str2+str3+str4+hap);
			if (res == 0)
			{
				MessageBox(_T("Sorry,he isn't include in our standard,try to practice."));
			}
			if (speed > 20 || jump > 20 || stamina > 20 || power > 20 || Longshoot > 20 || passing > 20 || Heading > 20 || Longpass > 20)
			{
				MessageBox(_T("pleass press again,the grade is over the ability."));
			}
		}
		if (btnStriker->GetCheck())
		{
			CString hap;
			int shoot = Shoot();
			int finish = getfinishfromcontroller();
			int movement = Movement();

			Striker* player4 = new Striker(NAME, age, speed, jump, stamina, finish, shoot, passing, Heading, movement);

			person = player4;
			workers.Add(person);

			CString str1;
			CString str2;
			CString str3;
			CString str4;
			str1.AppendFormat(name);
			str2.AppendFormat(_T(", Striker:"));

			str3.AppendFormat(_T(", Age : %d"), age);
			double res = player4->CalulateSalary();
			int time = player4->time_contract_for_player();
			hap.AppendFormat(_T(", for %d years"), time);
			str4.AppendFormat(_T(", salary  %2.lf"), res);
			
			CListBox* listWorkers = (CListBox*)GetDlgItem(listBoxWorkers);
			
			//listWorkers->AddString(str);
			listWorkers->AddString(str1 + str2 + str3 + str4+hap);
			MessageBox(str1 + str2 + str3 + str4 + hap);
			if (res==0)
			{
				MessageBox(_T("Sorry,he isn't include in our standard,try to practice."));
			}
			if (speed > 20 || jump > 20 || stamina > 20|| finish > 20 || shoot > 20 || passing > 20||Heading>20||movement>20)
			{
				MessageBox(_T("pleass press again,the grade is over the ability."));
			}
		}
		
		if (age > 30)
		{
			CString str;
			CString str7;
			str.AppendFormat(_T("His age is : %d"), age);
			str7.AppendFormat(_T(" , he is too old for us Good luck."));
			MessageBox(str + str7);
		}
	}
	if (btncoach->GetCheck())
	{
		CString hap;
		int years = Years_career();
		int games = Game_mangement();
		int tacticss = Tactics();
		int motivationn = Motivation();


		Manager *player5 = new Manager(NAME, age, years, games, tacticss, motivationn);
		person = player5;
		workers.Add(person);

		CString str1;
		CString str2;
		CString str3;
		CString str4;
		str1.AppendFormat(name);
		str2.AppendFormat(_T(" Coach:"));
		int time = player5->Calulatecontract();
		str3.AppendFormat(_T(" age  %d"), age);
		double res = player5->CalulateSalary();
		hap.AppendFormat(_T(", for %d years"), time);
		str4.AppendFormat(_T(" salary  %2.lf"), res);
		
		CListBox* listWorkers = (CListBox*)GetDlgItem(listBoxWorkers);

		MessageBox(str1 + str2 + str3 + str4 + hap);
		//listWorkers->AddString(str);
		listWorkers->AddString(str1 + str2 + str3 + str4+hap);
		
		if (age < 40 || years < 5 || games < 10 || tacticss < 10 || motivationn < 10)
		{
			MessageBox(_T("Sorry,he isn't include in our standard,try to practice."));
		}
		if (games > 20 || tacticss > 20 || motivationn > 20)
		{
			MessageBox(_T("pleass press again,the grade is over the ability."));
		}
	
	}
	if (!(btncoach->GetCheck()) && !(btnplayer->GetCheck()))
	{
		MessageBox(_T("please choose : Player or coach"));
	}


	CString str;

	CEdit* editAge = (CEdit*)GetDlgItem(btnEditAge);


	editAge->GetWindowTextW(str);



	char strToAtoi[10];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;
	
	if (number < 18)
	{
		MessageBox(_T("His age is :") + str + _T(" he is too young for us Good luck."));

	}
	/*if (number > 30)
	{
		MessageBox(_T("His age is :") + str + _T(" he is too old for us Good luck."));

	}*/





}


void CProjectDlg::OnBnClickedbtnplayer()
{


	CEdit* editName = (CEdit*)GetDlgItem(btnEditName);
	CEdit* editAge = (CEdit*)GetDlgItem(btnEditAge);
	CEdit* EditYears_Career = (CEdit*)GetDlgItem(btnEditYears_Career);
	//CINKPICTURE5* pic = (CINKPICTURE5*)GetDlgItem(IDC_INKPICTURE5);

	editName->EnableWindow(true);
	editAge->EnableWindow(true);
	CButton* btnGoalKeeper = (CButton*)GetDlgItem(btnRadioGoalKeeper);
	CButton* btnDeffender = (CButton*)GetDlgItem(btnRadioDeffender);
	CButton* btnMidfielder = (CButton*)GetDlgItem(btnRadioMidfielder);
	CButton* btnStriker = (CButton*)GetDlgItem(btnRadioStriker);

	btnGoalKeeper->EnableWindow(true);
	btnDeffender->EnableWindow(true);
	btnMidfielder->EnableWindow(true);
	btnStriker->EnableWindow(true);
	//EditYears_Career->ShowWindow(SW_HIDE);

//	pic->EnableWindow(true);

}


void CProjectDlg::OnBnClickedbtncoach()
{
	CEdit* editName = (CEdit*)GetDlgItem(btnEditName);
	CEdit* editAge = (CEdit*)GetDlgItem(btnEditAge);
	CButton* btnGoalKeeper = (CButton*)GetDlgItem(btnRadioGoalKeeper);
	CButton* btnDeffender = (CButton*)GetDlgItem(btnRadioDeffender);
	CButton* btnMidfielder = (CButton*)GetDlgItem(btnRadioMidfielder);
	CButton* btnStriker = (CButton*)GetDlgItem(btnRadioStriker);
	editName->EnableWindow(true);
	editAge->EnableWindow(true);

	btnGoalKeeper->EnableWindow(false);
	btnDeffender->EnableWindow(false);
	btnMidfielder->EnableWindow(false);
	btnStriker->EnableWindow(false);

}


void CProjectDlg::OnEnChangebtneditlongshoot3()
{

}


void CProjectDlg::OnBnClickedbtnradiostriker()
{
	// TODO: Add your control notification handler code here
	CEdit* editName = (CEdit*)GetDlgItem(btnEditName);
	CEdit* editAge = (CEdit*)GetDlgItem(btnEditAge);
	
	
}


void CProjectDlg::OnEnChangebtneditpower()
{

}



//void CProjectDlg::Serialize(CArchive& ar)
//{
//	
//}

int CProjectDlg::GetAgeFormController()
{
	CString str;

	CEdit* editAge = (CEdit*)GetDlgItem(btnEditAge);


	editAge->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}

CString CProjectDlg::GetNameFormController()
{
	CString name;
	GetDlgItemText(btnEditName, name);


	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", name);
	std::stringstream inputNumber(strToAtoi);
	
	return name;
}

void CProjectDlg::OnEnChangebtneditname()
{
	
	CEdit* editName = (CEdit*)GetDlgItem(btnEditName);
	CString str;

	//editName->GetWindowTextW(str);
	//MessageBox(str);
	// TODO:  Add your control notification handler code here
	char strToAtoi[10];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputString(strToAtoi);
	string s;
	inputString >> s;



}


void CProjectDlg::OnBnClickedbtnclear()
{

	int length = workers.GetSize();


	for (int i = 0; i < length; i++)
	{
		delete workers[i];
	}

	workers.RemoveAll();

	CListBox* list = (CListBox*)this->GetDlgItem(listBoxWorkers);

	list->ResetContent();
}


void CProjectDlg::OnBnClickedbtndelete()
{

	CListBox* list = (CListBox*)this->GetDlgItem(listBoxWorkers);

	int length = list->GetCount();

	if (length > 0)
	{
		int index = list->GetCaretIndex();

		if (0 <= index && index < length)
		{
			delete workers[index];
			workers.RemoveAt(index);

			UpdateList();
		}
	}

}

void CProjectDlg::UpdateList()
{
	Person* person = NULL;
	CListBox* list = (CListBox*)this->GetDlgItem(listBoxWorkers);
	list->ResetContent();
	//double result=CalulateSalary();
	for (int i = 0; i < workers.GetSize(); i++) {

		CString str;
		CString str1;
		CString str2;
		CString str3;
		CString str5;

		
		string NAME;
		string* my_name = &NAME;
		//name = GetNameFormController();//string NAME((CT2CA)name);
		////name = workers[i]->getName();
		//my_name = reinterpret_cast<string*>(&name);
		//CString name = GetNameFormController();
		
		//
		//double res = workers[i]->getsalary();
	//	str5.AppendFormat(_T("salary :%.2lf"),);
		//string NAME((CT2CA)name);
		CString name = GetNameFormController();
		string NAME1((CT2CA)name);
		//string strStr;
	//	strStr = GetNameFormController();

		//const char * theName = workers[i]->getName().c_str();
		const char * theName = NAME1.c_str();

		//CString name (theName);
		str.AppendFormat(name);
		//str1.AppendFormat(_T("\t goal keeper:\t"));
		str2.AppendFormat(_T(" Age :%d"), workers[i]->getage());
		str3.AppendFormat(_T(" The salary is:%.2lf"), workers[i]->change_salary());
		//workers[i]->CalulateSalary();
		list->AddString(str+str2+str3);
	}
}



void CProjectDlg::OnBnClickedbtnupdate()
{

	CListBox* list = (CListBox*)this->GetDlgItem(listBoxWorkers);

	int length = list->GetCount();

	if (length > 0)
	{
		int index = list->GetCaretIndex();

		if (0 <= index && index < length)
		{
			int age = GetAgeFormController();
			workers[index]->setage( age );
		   // workers[index]->getsalary() ;
			//workers[index]->CalulateSalary();
			UpdateList();
		}
	}


}



void CProjectDlg::OnLbnSelchangelistboxworkers()
{
	// TODO: Add your control notification handler code here
}


int CProjectDlg::getreflexfromcontroller()
{
	
	CString str;

	CEdit* EditReflex = (CEdit*)GetDlgItem(btnEditReflex);


	EditReflex->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getoneononefromcontroller()
{

	CString str;

	CEdit* Editoneonone = (CEdit*)GetDlgItem(btnEditOneOnOne);


	Editoneonone->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getspeedfromcontroller()
{

	CString str;

	CEdit* Editspeed = (CEdit*)GetDlgItem(btnEditSpeed);


	Editspeed->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getjumpfromcontroller()
{

	CString str;

	CEdit* Editjump = (CEdit*)GetDlgItem(btnEditJump);


	Editjump->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getstaminafromcontroller()
{

	CString str;

	CEdit* Editstamina = (CEdit*)GetDlgItem(btnEditStamina2);


	Editstamina->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getleadringfromcontroller()
{

	CString str;

	CEdit* EditLeadering = (CEdit*)GetDlgItem(btnEdieLeadering);


	EditLeadering->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getthrowingfromcontroller()
{

	CString str;

	CEdit* EditThrowing = (CEdit*)GetDlgItem(btnEditThrowing);


	EditThrowing->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getpowerfromcontroller()
{

	CString str;

	CEdit* Editpower = (CEdit*)GetDlgItem(btnEditPower3);


	Editpower->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getHeadingfromcontroller()
{

	CString str;

	CEdit* EditHeading = (CEdit*)GetDlgItem(btnEditHeading);


	EditHeading->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getpassingfromcontroller()
{

	CString str;

	CEdit* Editpassing = (CEdit*)GetDlgItem(btnEditPassing);


	Editpassing->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getsavingfromcontroller()
{

	CString str;

	CEdit* EditSaving = (CEdit*)GetDlgItem(btnEditSaving3);


	EditSaving->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getTacklesfromcontroller()
{

	CString str;

	CEdit* Tackles = (CEdit*)GetDlgItem(btnEditTackles);


	Tackles->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getbravefromcontroller()
{

	CString str;

	CEdit* brave = (CEdit*)GetDlgItem(btnEditBrave);


	brave->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getLongshoot2fromcontroller()
{

	CString str;

	CEdit* Longshoot2 = (CEdit*)GetDlgItem(btnEditLongshoot2);


	Longshoot2->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getLongPassfromcontroller()
{

	CString str;

	CEdit* LongPass = (CEdit*)GetDlgItem(btnEditLongPass);


	LongPass->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::getfinishfromcontroller()
{

	CString str;

	CEdit* Finish = (CEdit*)GetDlgItem(btnEditFinish3);


	Finish->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::Shoot()
{

	CString str;

	CEdit* Shoot = (CEdit*)GetDlgItem(btnEditShoot3);


	Shoot->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::Movement()
{

	CString str;

	CEdit* Movement = (CEdit*)GetDlgItem(btnEditMovement3);


	Movement->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::Years_career()
{

	CString str;

	CEdit* Years_career = (CEdit*)GetDlgItem(btnEditYears_Career);


	Years_career->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::Game_mangement()
{

	CString str;

	CEdit* Game_mangement = (CEdit*)GetDlgItem(btnEditGame_mangement);


	Game_mangement->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::Tactics()
{

	CString str;

	CEdit* Tactics = (CEdit*)GetDlgItem(btnEditTactics);


	Tactics->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}
int CProjectDlg::Motivation()
{

	CString str;

	CEdit* Motivation = (CEdit*)GetDlgItem(btnEditMotivation);


	Motivation->GetWindowTextW(str);

	char strToAtoi[100];

	sprintf_s(strToAtoi, "%S", str);
	std::stringstream inputNumber(strToAtoi);

	int number = 0;

	inputNumber >> number;

	return number;
}

void CProjectDlg::OnEnChangebtneditreflex()
{

}
void CProjectDlg::OnEnChangebtneditage()
{

}




void CProjectDlg::OnEnChangebtneditpower3()
{
	
}





void CProjectDlg::Serialize(CArchive& ar)
{
	//CObject::Serialize(ar);
	CString name = GetNameFormController();
	string NAME((CT2CA)name);

	int age = GetAgeFormController();

	

	if (ar.IsLoading())
	{
		ar >> name >> age;

	}
	else if (ar.IsStoring())
	{
		ar << name << age;
	}
}





//
//
//
//void CProjectDlg::OnBnClickedid()
//{
//	// FALSE to SAVE
//	CFileDialog dlg(FALSE, _T(".pong"), NULL, 0, _T("cPong (.pong)|.pong|All Files (.)|.||"));
//	CString filename;
//	if (dlg.DoModal() == IDOK)
//	{
//		filename = dlg.GetPathName(); // return full path and filename
//		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
//		CArchive ar(&file, CArchive::store);
//		for (int i = 0; i < workers.GetSize(); i++)
//		{
//			workers[i]->Serialize(ar);
//		}
//		//ar << level << score;
//		//ball->Serialize(ar);
//		//paddle[0]->Serialize(ar);
//		//paddle[level]->Serialize(ar);
//		//if (wall[0] != NULL) { wall[0]->Serialize(ar); }
//		//else { ar << 0; }
//		//if (wall[1] != NULL) { wall[1]->Serialize(ar); }
//		//else { ar << 0; }
//		ar.Close();
//		file.Close();
//	}
//}
//
//
//void CProjectDlg::OnBnClickedload()
//{
//	// TODO: Add your control notification handler code here
//	CFileDialog dlg(TRUE, _T(".pong"), NULL, 0, _T("cPong (.pong)|.pong|All Files (.)|.||"));
//	CString filename;
//	if (dlg.DoModal() == IDOK)
//	{
//		filename = dlg.GetPathName(); // return full path and filename
//		CFile file(filename, CFile::modeRead);
//		CArchive ar(&file, CArchive::load);
//		for(int i = 0; i < workers.GetSize(); i++)
//		{
//			workers[i]->Serialize(ar);
//		}
//		//initGame();
//		//ar >> level >> score;
//		//BackgdoundImage->Load(ImagesPath[level]);
//		//ball->Serialize(ar);
//		//paddle[0]->Serialize(ar);
//		//paddle[level]->Serialize(ar);
//		//wall[0]->Serialize(ar);
//		//wall[1]->Serialize(ar);
//		ar.Close();
//		file.Close();
//		Invalidate();
//	}
//}


void CProjectDlg::OnBnClickedid()
{
	const TCHAR czFilter[] = _T("FootballClub's files (*.agfm)|*.agfm|All Files (*.*)|*.*||");
	CFileDialog fDialog(FALSE, _T("agfm"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);

		workers.Serialize(ar);

		ar.Close();
		file.Close();
	}
}


void CProjectDlg::OnBnClickedload()
{
	const TCHAR czFilter[] = _T("FootballClub's files (*.agfm)|*.agfm|All Files (*.*)|*.*||");
	CFileDialog fDialog(TRUE, _T("agfm"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeRead);
		CArchive ar(&file, CArchive::load);

		OnBnClickedbtnclear();
		workers.Serialize(ar);

		ar.Close();
		file.Close();
		

		UpdateList();
	}
}



