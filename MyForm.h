#pragma once
#include <math.h>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"MyForm";
			this->Text = L"Ввод матрицы";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

		array<TextBox^>^ TB = gcnew array<TextBox^>(100);
		array<TextBox^>^ LB = gcnew array<TextBox^>(100);		
		int raz, eps;
		Form ^form = gcnew Form();
		Form ^finform = gcnew Form();
		TextBox ^textbox = gcnew TextBox();
		TextBox ^textbox1 = gcnew TextBox();

		
	public:void new_form(){
			   int i, j, k = 0;
			   int m = raz, n = raz;

			   for (i = 0; i < m; i++){
				   for (j = 0; j <= n; j++){
					   TB[k] = gcnew TextBox();
					   this->Controls->Add(TB[k]);
					   TB[k]->Size = System::Drawing::Size(60, 30);
					   TB[k]->Location = Point(5 + j * 70, 5 + i * 30);
					   if (m < 3 && n < 3){
						   this->ClientSize = System::Drawing::Size(5 + j * 110, 5 + i * 90);
					   }
					   if (m > 3 && n > 3){
						   this->ClientSize = System::Drawing::Size(5 + j * 90, 5 + i * 50);
					   }
					   if (m == 3 && n == 3){
						   this->ClientSize = System::Drawing::Size(5 + j * 95, 5 + i * 60);
					   }
					   k++;
				   }
			   }

			   Button ^button = gcnew Button();
			   this->Controls->Add(button);
			   button->Location = Point(System::Drawing::Size(5 + j * 50, 5 + i * 29));
			   button->Name = L"button";
			   button->Size = System::Drawing::Size(50, 25);
			   button->TabIndex = 1;
			   button->Text = L"Ok";
			   button->UseVisualStyleBackColor = true;

			   button->Click += gcnew EventHandler(this, &MyForm::button_click);
	}

	public:void enter_form(){
			   form->Show();

			   //
			   //Button
			   //
			   Button ^button = gcnew Button();
			   form->Controls->Add(button);
			   button->Location = Point(System::Drawing::Size(50, 120));
			   button->Name = L"button1";
			   button->Size = System::Drawing::Size(50, 25);
			   button->TabIndex = 1;
			   button->Text = L"Ok";
			   button->UseVisualStyleBackColor = true;
			   //
			   //TextBox
			   //
			   form->Controls->Add(textbox);
			   textbox->Location = System::Drawing::Point(30, 30);
			   textbox->Name = L"textBox";
			   textbox->Size = System::Drawing::Size(50, 20);
			   textbox->TabIndex = 0;
			   //
			   //TextBox1
			   //
			   form->Controls->Add(textbox1);
			   textbox1->Location = System::Drawing::Point(30, 85);
			   textbox1->Name = L"textBox1";
			   textbox1->Size = System::Drawing::Size(50, 20);
			   textbox1->TabIndex = 0;
			   //
			   //Label
			   //
			   Label ^label = gcnew Label();
			   form->Controls->Add(label);
			   label->AutoSize = true;
			   label->Location = System::Drawing::Point(2, 10);
			   label->Name = L"label";
			   label->Size = System::Drawing::Size(35, 13);
			   label->TabIndex = 0;
			   label->Text = L"Размерность матрицы";
			   //
			   //Label1
			   //
			   Label ^label1 = gcnew Label();
			   form->Controls->Add(label1);
			   label1->AutoSize = true;
			   label1->Location = System::Drawing::Point(28, 70);
			   label1->Name = L"label1";
			   label1->Size = System::Drawing::Size(35, 13);
			   label1->TabIndex = 0;
			   label1->Text = L"Точность";

			   form->ClientSize = System::Drawing::Size(75, 150);
			   button->Click += gcnew EventHandler(this, &MyForm::button1_click);


	}


		   template <typename T> void PrintMtx(T *mat, int n){
			   int k = 0;
			   for (int i = 0; i < n; i++){				
					   mat[i] = round(mat[i] * 100) / 100;
					   LB[k]->Text = Convert::ToString("X" + i + " = " + mat[i]);
					   k++;				  					    
			   }
		   }


		   template <typename T> void MainDiag(T **mat, T *free, int n){
			   double *main;
			   main = new double[n];
			   int i, j, k=0;
			   
			   for (i = 0; i < n; i++){
				   for (j = 0; j < n; j++){
					   if (i == j){
						   main[i] = mat[i][j];
						   free[i] = free[i] / main[i];
						   mat[i][j] = 0;
					   }
				   }
			   }

			   for (i = 0; i < n; i++){
				   for (j = 0; j < n; j++){
					   if (i != j){
						   mat[i][j] = (mat[i][j] / main[i])*(-1);
					   }
				   }
			   }
			   delete main;
		   }

		   //функция ввода матрицы
		   void mat_R(double **mat, double *free, int n){
			   int k = 0;
			   int mem;
			   for (int i = 0; i < n; i++){
				   mem = 0;
				   if (i == 0){
					   mem = n;
				   }
				   else{
					   mem = k + n;
				   }
				   for (int j = 0; j <= n; j++){
					   if (!(k == mem)){
						   mat[i][j] = Convert::ToDouble(TB[k]->Text);
					   }
					   else{
						   free[i] = Convert::ToDouble(TB[k]->Text);
					   }   
					   k++;
				   }
			   }
		   }

		   //Функция освобождения памяти
		   template <typename T> void FreeMem(T **mat, int n)
		   {
			   for (int i = 0; i < n; i++)
				 for (int j = 0; j < n;j++)
					 mat[i][j]=0;	  
		   }

		   template <typename T> void FreeMemOne(T *mat){
			   delete mat;
		   }

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 enter_form();
				 this->WindowState = FormWindowState::Minimized;
				 ShowInTaskbar = false;
	}

	private: System::Void button1_click(System::Object ^ sender, System::EventArgs ^ e){
					 raz = Convert::ToDouble(textbox->Text);
					 eps = Convert::ToDouble(textbox1->Text);
					 new_form();
					 this->WindowState = FormWindowState::Normal;
					 ShowInTaskbar = true;
					 form->Close();
		}
			
			 
	private: System::Void button_click(System::Object ^ sender, System::EventArgs ^ e){
				 double **mat;
				 double *x;
				 double *alphax;	//c
				 double *free;
				 double *buf;
				 double l, *sum;
				 int i, j, n = raz, m = raz;
				 sum = new double[n];
				 mat = new double*[n];
				 x = new double[n];
				 alphax = new double[n];	//c
				 free = new double[n];
				 buf = new double[n];

				 Fin_form();

				 for (i = 0; i < n; i++){
					 mat[i] = new double[m];
				 }

				mat_R(mat, free, n);
				MainDiag(mat, free, n);

				for (i = 0; i < n; i++){
					 buf[i] = free[i];
				 }

				 do
				 {
					 for (i = 0; i < n; i++){
						 alphax[i] = 0;
						 x[i] = buf[i];
						 for (j = 0; j < n; j++){
							 alphax[i] += mat[i][j] * buf[j];
						 }
					 }

					 for (i = 0; i < n; i++){
						 sum[i] = alphax[i] + free[i];
						 buf[i] = sum[i];				
					 }
					 l = sqrt(pow(x[0] - buf[0], 2) + pow(x[1] - buf[1], 2) + pow(x[2] - buf[2], 2));
				 } while (fabs(l) < eps);

				 FreeMem(mat, n);
				 PrintMtx(buf, n);
				 FreeMemOne(alphax);
				 FreeMemOne(free);
				 FreeMemOne(buf);
				 FreeMemOne(x);
				 FreeMemOne(sum);
	}
	public:void Fin_form(){
			   int i, j, k=0;
			   int m = 1, n = raz;

			   finform->Show();
			   finform->Text = L"Корни";
			   for (i = 0; i < n; i++){
				   for (j = 0; j < m; j++){
					   LB[i] = gcnew TextBox();
					   finform->Controls->Add(LB[i]);
					   LB[i]->Size = System::Drawing::Size(100, 30);
					   LB[i]->Location = Point(20, 5 + i * 30);
					   if (n < 3){
						   finform->ClientSize = System::Drawing::Size(50, 5 + i * 60);
					   }
					   if (n > 3){
						   finform->ClientSize = System::Drawing::Size(50, 5 + i * 80);
					   }
					   if (n == 3){
						   finform->ClientSize = System::Drawing::Size(50, 5 + i * 50);
					   }
					  // k++;
				   }
			   }
	}

	};
}
