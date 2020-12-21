#pragma once
#include "Calculator.h"
#include "inf_int.h"
namespace CALCULATORGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtDisplay;
	private: System::Windows::Forms::Button^ btn1;
	private: System::Windows::Forms::Button^ btndel;
	protected:

	protected:












	private: System::Windows::Forms::Button^ btn2;
	private: System::Windows::Forms::Button^ btn3;
	private: System::Windows::Forms::Button^ btn6;



	private: System::Windows::Forms::Button^ btn5;

	private: System::Windows::Forms::Button^ btn4;
	private: System::Windows::Forms::Button^ btn9;


	private: System::Windows::Forms::Button^ btn8;

	private: System::Windows::Forms::Button^ btn7;
	private: System::Windows::Forms::Button^ btn0;
	private: System::Windows::Forms::Button^ btnequal;
	private: System::Windows::Forms::Button^ btnplus;





	private: System::Windows::Forms::Button^ btnminus;

	private: System::Windows::Forms::Button^ btnmul;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;





	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtDisplay = (gcnew System::Windows::Forms::TextBox());
			this->btn1 = (gcnew System::Windows::Forms::Button());
			this->btndel = (gcnew System::Windows::Forms::Button());
			this->btn2 = (gcnew System::Windows::Forms::Button());
			this->btn3 = (gcnew System::Windows::Forms::Button());
			this->btn6 = (gcnew System::Windows::Forms::Button());
			this->btn5 = (gcnew System::Windows::Forms::Button());
			this->btn4 = (gcnew System::Windows::Forms::Button());
			this->btn9 = (gcnew System::Windows::Forms::Button());
			this->btn8 = (gcnew System::Windows::Forms::Button());
			this->btn7 = (gcnew System::Windows::Forms::Button());
			this->btn0 = (gcnew System::Windows::Forms::Button());
			this->btnequal = (gcnew System::Windows::Forms::Button());
			this->btnplus = (gcnew System::Windows::Forms::Button());
			this->btnminus = (gcnew System::Windows::Forms::Button());
			this->btnmul = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtDisplay
			// 
			this->txtDisplay->Font = (gcnew System::Drawing::Font(L"굴림", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->txtDisplay->Location = System::Drawing::Point(16, 12);
			this->txtDisplay->Multiline = true;
			this->txtDisplay->Name = L"txtDisplay";
			this->txtDisplay->Size = System::Drawing::Size(468, 30);
			this->txtDisplay->TabIndex = 0;
			this->txtDisplay->Text = L"Click the START";
			this->txtDisplay->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txtDisplay->TextChanged += gcnew System::EventHandler(this, &MyForm::txtDisplay_TextChanged);
			// 
			// btn1
			// 
			this->btn1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn1->Location = System::Drawing::Point(32, 48);
			this->btn1->Name = L"btn1";
			this->btn1->Size = System::Drawing::Size(87, 68);
			this->btn1->TabIndex = 1;
			this->btn1->TabStop = false;
			this->btn1->Text = L"1";
			this->btn1->UseVisualStyleBackColor = true;
			this->btn1->Click += gcnew System::EventHandler(this, &MyForm::Enternum);
			// 
			// btndel
			// 
			this->btndel->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btndel->Font = (gcnew System::Drawing::Font(L"Wingdings", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->btndel->Location = System::Drawing::Point(317, 48);
			this->btndel->Name = L"btndel";
			this->btndel->Size = System::Drawing::Size(138, 68);
			this->btndel->TabIndex = 12;
			this->btndel->TabStop = false;
			this->btndel->Text = L"";
			this->btndel->UseVisualStyleBackColor = false;
			this->btndel->Click += gcnew System::EventHandler(this, &MyForm::btndel_Click);
			// 
			// btn2
			// 
			this->btn2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn2->Location = System::Drawing::Point(125, 48);
			this->btn2->Name = L"btn2";
			this->btn2->Size = System::Drawing::Size(87, 68);
			this->btn2->TabIndex = 16;
			this->btn2->TabStop = false;
			this->btn2->Text = L"2";
			this->btn2->UseVisualStyleBackColor = true;
			this->btn2->Click += gcnew System::EventHandler(this, &MyForm::Enternum);
			// 
			// btn3
			// 
			this->btn3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn3->Location = System::Drawing::Point(218, 48);
			this->btn3->Name = L"btn3";
			this->btn3->Size = System::Drawing::Size(87, 68);
			this->btn3->TabIndex = 17;
			this->btn3->TabStop = false;
			this->btn3->Text = L"3";
			this->btn3->UseVisualStyleBackColor = true;
			this->btn3->Click += gcnew System::EventHandler(this, &MyForm::Enternum);
			// 
			// btn6
			// 
			this->btn6->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn6->Location = System::Drawing::Point(218, 122);
			this->btn6->Name = L"btn6";
			this->btn6->Size = System::Drawing::Size(87, 68);
			this->btn6->TabIndex = 20;
			this->btn6->TabStop = false;
			this->btn6->Text = L"6";
			this->btn6->UseVisualStyleBackColor = true;
			this->btn6->Click += gcnew System::EventHandler(this, &MyForm::Enternum);
			// 
			// btn5
			// 
			this->btn5->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn5->Location = System::Drawing::Point(125, 122);
			this->btn5->Name = L"btn5";
			this->btn5->Size = System::Drawing::Size(87, 68);
			this->btn5->TabIndex = 19;
			this->btn5->TabStop = false;
			this->btn5->Text = L"5";
			this->btn5->UseVisualStyleBackColor = true;
			this->btn5->Click += gcnew System::EventHandler(this, &MyForm::Enternum);
			// 
			// btn4
			// 
			this->btn4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn4->Location = System::Drawing::Point(32, 122);
			this->btn4->Name = L"btn4";
			this->btn4->Size = System::Drawing::Size(87, 68);
			this->btn4->TabIndex = 18;
			this->btn4->TabStop = false;
			this->btn4->Text = L"4";
			this->btn4->UseVisualStyleBackColor = true;
			this->btn4->Click += gcnew System::EventHandler(this, &MyForm::Enternum);
			// 
			// btn9
			// 
			this->btn9->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn9->Location = System::Drawing::Point(218, 196);
			this->btn9->Name = L"btn9";
			this->btn9->Size = System::Drawing::Size(87, 68);
			this->btn9->TabIndex = 23;
			this->btn9->TabStop = false;
			this->btn9->Text = L"9";
			this->btn9->UseVisualStyleBackColor = true;
			this->btn9->Click += gcnew System::EventHandler(this, &MyForm::Enternum);
			// 
			// btn8
			// 
			this->btn8->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn8->Location = System::Drawing::Point(125, 196);
			this->btn8->Name = L"btn8";
			this->btn8->Size = System::Drawing::Size(87, 68);
			this->btn8->TabIndex = 22;
			this->btn8->TabStop = false;
			this->btn8->Text = L"8";
			this->btn8->UseVisualStyleBackColor = true;
			this->btn8->Click += gcnew System::EventHandler(this, &MyForm::Enternum);
			// 
			// btn7
			// 
			this->btn7->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn7->Location = System::Drawing::Point(32, 196);
			this->btn7->Name = L"btn7";
			this->btn7->Size = System::Drawing::Size(87, 68);
			this->btn7->TabIndex = 21;
			this->btn7->TabStop = false;
			this->btn7->Text = L"7";
			this->btn7->UseVisualStyleBackColor = true;
			this->btn7->Click += gcnew System::EventHandler(this, &MyForm::Enternum);
			// 
			// btn0
			// 
			this->btn0->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn0->Location = System::Drawing::Point(32, 274);
			this->btn0->Name = L"btn0";
			this->btn0->Size = System::Drawing::Size(87, 68);
			this->btn0->TabIndex = 24;
			this->btn0->TabStop = false;
			this->btn0->Text = L"0";
			this->btn0->UseVisualStyleBackColor = true;
			this->btn0->Click += gcnew System::EventHandler(this, &MyForm::Enternum);
			// 
			// btnequal
			// 
			this->btnequal->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->btnequal->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnequal->Location = System::Drawing::Point(125, 274);
			this->btnequal->Name = L"btnequal";
			this->btnequal->Size = System::Drawing::Size(180, 68);
			this->btnequal->TabIndex = 25;
			this->btnequal->TabStop = false;
			this->btnequal->Text = L"=";
			this->btnequal->UseVisualStyleBackColor = false;
			this->btnequal->Click += gcnew System::EventHandler(this, &MyForm::btnequal_Click);
			// 
			// btnplus
			// 
			this->btnplus->BackColor = System::Drawing::Color::DarkOrange;
			this->btnplus->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnplus->Location = System::Drawing::Point(317, 196);
			this->btnplus->Name = L"btnplus";
			this->btnplus->Size = System::Drawing::Size(66, 68);
			this->btnplus->TabIndex = 26;
			this->btnplus->TabStop = false;
			this->btnplus->Text = L"+";
			this->btnplus->UseVisualStyleBackColor = false;
			this->btnplus->Click += gcnew System::EventHandler(this, &MyForm::Enteroper);
			// 
			// btnminus
			// 
			this->btnminus->BackColor = System::Drawing::Color::DarkOrange;
			this->btnminus->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnminus->Location = System::Drawing::Point(389, 196);
			this->btnminus->Name = L"btnminus";
			this->btnminus->Size = System::Drawing::Size(66, 68);
			this->btnminus->TabIndex = 27;
			this->btnminus->TabStop = false;
			this->btnminus->Text = L"-";
			this->btnminus->UseVisualStyleBackColor = false;
			this->btnminus->Click += gcnew System::EventHandler(this, &MyForm::Enteroper);
			// 
			// btnmul
			// 
			this->btnmul->BackColor = System::Drawing::Color::DarkOrange;
			this->btnmul->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnmul->Location = System::Drawing::Point(389, 122);
			this->btnmul->Name = L"btnmul";
			this->btnmul->Size = System::Drawing::Size(66, 68);
			this->btnmul->TabIndex = 28;
			this->btnmul->TabStop = false;
			this->btnmul->Text = L"*";
			this->btnmul->UseVisualStyleBackColor = false;
			this->btnmul->Click += gcnew System::EventHandler(this, &MyForm::Enteroper);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DarkOrange;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(317, 270);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(66, 68);
			this->button1->TabIndex = 29;
			this->button1->TabStop = false;
			this->button1->Text = L"(";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Enteroper);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::DarkOrange;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(389, 270);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(66, 68);
			this->button2->TabIndex = 30;
			this->button2->TabStop = false;
			this->button2->Text = L")";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Enteroper);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Red;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(317, 122);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(66, 68);
			this->button3->TabIndex = 31;
			this->button3->TabStop = false;
			this->button3->Text = L"START";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(446, 341);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 12);
			this->label1->TabIndex = 32;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->ClientSize = System::Drawing::Size(493, 356);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnmul);
			this->Controls->Add(this->btnminus);
			this->Controls->Add(this->btnplus);
			this->Controls->Add(this->btnequal);
			this->Controls->Add(this->btn0);
			this->Controls->Add(this->btn9);
			this->Controls->Add(this->btn8);
			this->Controls->Add(this->btn7);
			this->Controls->Add(this->btn6);
			this->Controls->Add(this->btn5);
			this->Controls->Add(this->btn4);
			this->Controls->Add(this->btn3);
			this->Controls->Add(this->btn2);
			this->Controls->Add(this->btndel);
			this->Controls->Add(this->btn1);
			this->Controls->Add(this->txtDisplay);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Infinete Integer Calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::Myform_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Enternum(System::Object^ sender, System::EventArgs^ e) {
	Button^ number = safe_cast<Button^>(sender);
	ClearScr();
	if (txtDisplay->Text == "0")
	{
		txtDisplay->Text = number->Text;
	}
	else
	{
		txtDisplay->Text += number->Text;
	}
	label1->Focus();
}
private: System::Void Enteroper(System::Object^ sender, System::EventArgs^ e) {
	Button^ number = safe_cast<Button^>(sender);
	ClearScr();
	if (txtDisplay->Text == "0")
	{
		txtDisplay->Text = number->Text;
	}
	else
	{
		txtDisplay->Text = txtDisplay->Text + " " + number->Text +" ";
	}
	label1->Focus();
}
private: void ClearScr() {
   if (this->txtDisplay->Text == "Error") {
	   this->txtDisplay->Text = "";
   }
}
 private: System::Void Enter()
 {
	Calculator Calc;
	std::string data;
	for (int i = 0; i < this->txtDisplay->Text->Length; i++) {
		   data.push_back(this->txtDisplay->Text[i]);
	}
	this->txtDisplay->Text = "";
	if (!data.empty()) {
			inf_int result;
		   result = Calc.Calculation(data);
		   if (!Calc.isValid()) this->txtDisplay->Text = "Error";
		   else
		   {
			   for (auto v : result.toString())
				   this->txtDisplay->Text += (wchar_t)v;
		   }
	}

 }

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->button3->Text == "START")
	{
		this->button3->Text = L"CE";
		this->button3->BackColor = System::Drawing::Color::DarkOrange;
		this->txtDisplay->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
		this->txtDisplay->Text = "0";
	}
	this->txtDisplay->Text = "0";
	label1->Focus();
}
private: System::Void btndel_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->txtDisplay->Text->Length)
		this->txtDisplay->Text = this->txtDisplay->Text->Remove(this->txtDisplay->Text->Length - 1, 1);
	label1->Focus();
}
private: System::Void btnequal_Click(System::Object^ sender, System::EventArgs^ e) {
	Enter();
	label1->Focus();
}
private: System::Void txtDisplay_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Myform_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode) {
		ClearScr();
	case Keys::Enter:
		this->txtDisplay->Text == "";
		Enter();
		break;
	case Keys::NumPad0: case Keys::D0:
		if (this->txtDisplay->Text == "0") {
			this->txtDisplay->Text = "";
		}
		this->txtDisplay->Text += "0";
		break;
	case Keys::NumPad1: case Keys::D1:
		if (this->txtDisplay->Text == "0") {
			this->txtDisplay->Text = "";
		}
		this->txtDisplay->Text += "1";
		break;
	case Keys::NumPad2: case Keys::D2:
		if (this->txtDisplay->Text == "0") {
			this->txtDisplay->Text = "";
		}
		this->txtDisplay->Text += "2";
		break;
	case Keys::NumPad3: case Keys::D3:
		if (this->txtDisplay->Text == "0") {
			this->txtDisplay->Text = "";
		}
		this->txtDisplay->Text += "3";
		break;
	case Keys::NumPad4: case Keys::D4:
		if (this->txtDisplay->Text == "0") {
			this->txtDisplay->Text = "";
		}
		this->txtDisplay->Text += "4";
		break;
	case Keys::NumPad5: case Keys::D5:
		if (this->txtDisplay->Text == "0") {
			this->txtDisplay->Text = "";
		}
		this->txtDisplay->Text += "5";
		break;
	case Keys::NumPad6: case Keys::D6:
		if (this->txtDisplay->Text == "0") {
			this->txtDisplay->Text = "";
		}
		this->txtDisplay->Text += "6";
		break;
	case Keys::NumPad7: case Keys::D7:
		if (this->txtDisplay->Text == "0") {
			this->txtDisplay->Text = "";
		}
		this->txtDisplay->Text += "7";
		break;
	case Keys::NumPad8: case Keys::D8:
		if (this->txtDisplay->Text == "0") {
			this->txtDisplay->Text = "";
		}
		this->txtDisplay->Text += "8";
		break;
	case Keys::NumPad9: case Keys::D9:
		if (this->txtDisplay->Text == "0") {
			this->txtDisplay->Text = "";
		}
		this->txtDisplay->Text += "9";
		break;
	case Keys::Delete:
		// this->txtDisplay->Text += "";
		break;
	case Keys::Back:
		if (this->txtDisplay->Text->Length)
			this->txtDisplay->Text = this->txtDisplay->Text->Remove(this->txtDisplay->Text->Length - 1, 1);
		break;
	case Keys::Multiply:
		this->txtDisplay->Text += " * ";
		break;
	case Keys::Add:
		this->txtDisplay->Text += " + ";
		break;
	case Keys::Subtract:
		this->txtDisplay->Text += " - ";
		break;
	case Keys::Space:
		this->txtDisplay->Text += " ";
		break;
	case Keys::OemOpenBrackets:
		this->txtDisplay->Text += " ( ";
		break;
	case Keys::OemCloseBrackets:
		this->txtDisplay->Text += " ) ";
		break;

	}
}
};
}
