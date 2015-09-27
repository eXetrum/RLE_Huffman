#pragma once

#include "RLE_HUFF.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	

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
	private: System::Windows::Forms::Button^  btn_rle_enc;
	private: System::Windows::Forms::TextBox^  txt_TEXT;
	private: System::Windows::Forms::TextBox^  txt_ENCODE;
	private: System::Windows::Forms::TextBox^  txt_Huff_TAB;

	protected: 

	protected: 



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btn_rle_dec;


	private: System::Windows::Forms::TabControl^  tab_ctrl;
	private: System::Windows::Forms::TabPage^  tab_RLE;
	private: System::Windows::Forms::TabPage^  tab_Huffman;
	private: System::Windows::Forms::TextBox^  txt_Huff_DEC;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txt_Huff_ENC;

	private: System::Windows::Forms::Button^  btn_huf_dec;
	private: System::Windows::Forms::Button^  btn_huf_enc;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  txt_TEXT_BIN;







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
			this->btn_rle_enc = (gcnew System::Windows::Forms::Button());
			this->txt_TEXT = (gcnew System::Windows::Forms::TextBox());
			this->txt_ENCODE = (gcnew System::Windows::Forms::TextBox());
			this->txt_Huff_TAB = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btn_rle_dec = (gcnew System::Windows::Forms::Button());
			this->tab_ctrl = (gcnew System::Windows::Forms::TabControl());
			this->tab_RLE = (gcnew System::Windows::Forms::TabPage());
			this->tab_Huffman = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txt_TEXT_BIN = (gcnew System::Windows::Forms::TextBox());
			this->txt_Huff_DEC = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txt_Huff_ENC = (gcnew System::Windows::Forms::TextBox());
			this->btn_huf_dec = (gcnew System::Windows::Forms::Button());
			this->btn_huf_enc = (gcnew System::Windows::Forms::Button());
			this->tab_ctrl->SuspendLayout();
			this->tab_RLE->SuspendLayout();
			this->tab_Huffman->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_rle_enc
			// 
			this->btn_rle_enc->Enabled = false;
			this->btn_rle_enc->Location = System::Drawing::Point(6, 151);
			this->btn_rle_enc->Name = L"btn_rle_enc";
			this->btn_rle_enc->Size = System::Drawing::Size(126, 31);
			this->btn_rle_enc->TabIndex = 0;
			this->btn_rle_enc->Text = L"RLE encode";
			this->btn_rle_enc->UseVisualStyleBackColor = true;
			this->btn_rle_enc->Click += gcnew System::EventHandler(this, &MyForm::btn_rle_enc_Click);
			// 
			// txt_TEXT
			// 
			this->txt_TEXT->Location = System::Drawing::Point(6, 19);
			this->txt_TEXT->Multiline = true;
			this->txt_TEXT->Name = L"txt_TEXT";
			this->txt_TEXT->Size = System::Drawing::Size(265, 126);
			this->txt_TEXT->TabIndex = 1;
			this->txt_TEXT->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_TEXT_TextChanged);
			// 
			// txt_ENCODE
			// 
			this->txt_ENCODE->Location = System::Drawing::Point(6, 207);
			this->txt_ENCODE->Multiline = true;
			this->txt_ENCODE->Name = L"txt_ENCODE";
			this->txt_ENCODE->Size = System::Drawing::Size(264, 127);
			this->txt_ENCODE->TabIndex = 2;
			this->txt_ENCODE->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_ENCODE_TextChanged);
			// 
			// txt_Huff_TAB
			// 
			this->txt_Huff_TAB->AcceptsTab = true;
			this->txt_Huff_TAB->Location = System::Drawing::Point(277, 19);
			this->txt_Huff_TAB->Multiline = true;
			this->txt_Huff_TAB->Name = L"txt_Huff_TAB";
			this->txt_Huff_TAB->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_Huff_TAB->Size = System::Drawing::Size(264, 140);
			this->txt_Huff_TAB->TabIndex = 3;
			this->txt_Huff_TAB->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_Huff_TAB_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(234, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Текст";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(209, 191);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Кодировка";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(360, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Таблица Huffman";
			// 
			// btn_rle_dec
			// 
			this->btn_rle_dec->Enabled = false;
			this->btn_rle_dec->Location = System::Drawing::Point(145, 151);
			this->btn_rle_dec->Name = L"btn_rle_dec";
			this->btn_rle_dec->Size = System::Drawing::Size(126, 31);
			this->btn_rle_dec->TabIndex = 7;
			this->btn_rle_dec->Text = L"RLE decode";
			this->btn_rle_dec->UseVisualStyleBackColor = true;
			this->btn_rle_dec->Click += gcnew System::EventHandler(this, &MyForm::btn_rle_dec_Click);
			// 
			// tab_ctrl
			// 
			this->tab_ctrl->Controls->Add(this->tab_RLE);
			this->tab_ctrl->Controls->Add(this->tab_Huffman);
			this->tab_ctrl->Location = System::Drawing::Point(12, 12);
			this->tab_ctrl->Name = L"tab_ctrl";
			this->tab_ctrl->SelectedIndex = 0;
			this->tab_ctrl->Size = System::Drawing::Size(555, 379);
			this->tab_ctrl->TabIndex = 10;
			// 
			// tab_RLE
			// 
			this->tab_RLE->Controls->Add(this->btn_rle_enc);
			this->tab_RLE->Controls->Add(this->btn_rle_dec);
			this->tab_RLE->Controls->Add(this->txt_TEXT);
			this->tab_RLE->Controls->Add(this->label1);
			this->tab_RLE->Controls->Add(this->label2);
			this->tab_RLE->Controls->Add(this->txt_ENCODE);
			this->tab_RLE->Location = System::Drawing::Point(4, 22);
			this->tab_RLE->Name = L"tab_RLE";
			this->tab_RLE->Padding = System::Windows::Forms::Padding(3);
			this->tab_RLE->Size = System::Drawing::Size(547, 353);
			this->tab_RLE->TabIndex = 0;
			this->tab_RLE->Text = L"RLE";
			this->tab_RLE->UseVisualStyleBackColor = true;
			// 
			// tab_Huffman
			// 
			this->tab_Huffman->Controls->Add(this->label6);
			this->tab_Huffman->Controls->Add(this->txt_TEXT_BIN);
			this->tab_Huffman->Controls->Add(this->txt_Huff_DEC);
			this->tab_Huffman->Controls->Add(this->label4);
			this->tab_Huffman->Controls->Add(this->label5);
			this->tab_Huffman->Controls->Add(this->txt_Huff_ENC);
			this->tab_Huffman->Controls->Add(this->txt_Huff_TAB);
			this->tab_Huffman->Controls->Add(this->btn_huf_dec);
			this->tab_Huffman->Controls->Add(this->label3);
			this->tab_Huffman->Controls->Add(this->btn_huf_enc);
			this->tab_Huffman->Location = System::Drawing::Point(4, 22);
			this->tab_Huffman->Name = L"tab_Huffman";
			this->tab_Huffman->Padding = System::Windows::Forms::Padding(3);
			this->tab_Huffman->Size = System::Drawing::Size(547, 353);
			this->tab_Huffman->TabIndex = 1;
			this->tab_Huffman->Text = L"Huffman";
			this->tab_Huffman->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(95, 162);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(71, 13);
			this->label6->TabIndex = 15;
			this->label6->Text = L"Текст | Биты";
			// 
			// txt_TEXT_BIN
			// 
			this->txt_TEXT_BIN->Location = System::Drawing::Point(6, 178);
			this->txt_TEXT_BIN->Multiline = true;
			this->txt_TEXT_BIN->Name = L"txt_TEXT_BIN";
			this->txt_TEXT_BIN->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_TEXT_BIN->Size = System::Drawing::Size(265, 126);
			this->txt_TEXT_BIN->TabIndex = 14;
			// 
			// txt_Huff_DEC
			// 
			this->txt_Huff_DEC->Location = System::Drawing::Point(6, 19);
			this->txt_Huff_DEC->Multiline = true;
			this->txt_Huff_DEC->Name = L"txt_Huff_DEC";
			this->txt_Huff_DEC->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_Huff_DEC->Size = System::Drawing::Size(265, 140);
			this->txt_Huff_DEC->TabIndex = 10;
			this->txt_Huff_DEC->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_Huff_DEC_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(117, 3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Текст";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(360, 162);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Кодировка | Биты";
			// 
			// txt_Huff_ENC
			// 
			this->txt_Huff_ENC->Location = System::Drawing::Point(277, 178);
			this->txt_Huff_ENC->Multiline = true;
			this->txt_Huff_ENC->Name = L"txt_Huff_ENC";
			this->txt_Huff_ENC->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txt_Huff_ENC->Size = System::Drawing::Size(264, 127);
			this->txt_Huff_ENC->TabIndex = 11;
			this->txt_Huff_ENC->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_Huff_ENC_TextChanged);
			// 
			// btn_huf_dec
			// 
			this->btn_huf_dec->Enabled = false;
			this->btn_huf_dec->Location = System::Drawing::Point(337, 310);
			this->btn_huf_dec->Name = L"btn_huf_dec";
			this->btn_huf_dec->Size = System::Drawing::Size(126, 31);
			this->btn_huf_dec->TabIndex = 9;
			this->btn_huf_dec->Text = L"Huffman decode";
			this->btn_huf_dec->UseVisualStyleBackColor = true;
			this->btn_huf_dec->Click += gcnew System::EventHandler(this, &MyForm::btn_huf_dec_Click);
			// 
			// btn_huf_enc
			// 
			this->btn_huf_enc->Enabled = false;
			this->btn_huf_enc->Location = System::Drawing::Point(75, 310);
			this->btn_huf_enc->Name = L"btn_huf_enc";
			this->btn_huf_enc->Size = System::Drawing::Size(127, 31);
			this->btn_huf_enc->TabIndex = 8;
			this->btn_huf_enc->Text = L"Huffman encode";
			this->btn_huf_enc->UseVisualStyleBackColor = true;
			this->btn_huf_enc->Click += gcnew System::EventHandler(this, &MyForm::btn_huf_enc_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 402);
			this->Controls->Add(this->tab_ctrl);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"RLE / Huffman";
			this->tab_ctrl->ResumeLayout(false);
			this->tab_RLE->ResumeLayout(false);
			this->tab_RLE->PerformLayout();
			this->tab_Huffman->ResumeLayout(false);
			this->tab_Huffman->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

//

private: System::Void btn_rle_enc_Click(System::Object^  sender, System::EventArgs^  e) {
			// Получаем текст для кодирования
			String ^input = txt_TEXT->Text;
			// Кодируем и выводим в поле "кодировка"
			txt_ENCODE->Text = RLE_HUFF::RleEncode(input);
		}
private: System::Void btn_rle_dec_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Получаем текст для декодирования
			String ^input = txt_ENCODE->Text;
			// Проверяем корректность текста представляющего кодировку RLE
			if(!RLE_HUFF::IsCorrectRleEncode(input))
			{
				MessageBox::Show("Кодировка не корректна !");
			}
			else
			{
				// Перекодируем и выводим в поле "текст"
				txt_TEXT->Text = RLE_HUFF::RleDecode(input);
			}
		 }
private: System::Void btn_huf_enc_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Очищаем поле вывода таблицы кодов
			 txt_Huff_TAB->Clear();
			 // Получаем текст для закодирования
			 String ^text = txt_Huff_DEC->Text;
			 // Получаем татблицу кодов
			 Dictionary<Char, String^> ^tb = RLE_HUFF::GetHuffmanTable(text);
			 // Выводим таблицу
			 for each (KeyValuePair<Char, String^> var in tb)
			 {
				 txt_Huff_TAB->AppendText(var.Key + "\t" + var.Value + Environment::NewLine);
			 }
			 txt_Huff_ENC->Text = RLE_HUFF::HuffmanEncode(text);
			 
		 }
private: System::Void btn_huf_dec_Click(System::Object^  sender, System::EventArgs^  e) {
			 // Получаем кодированный текст из нулей и единиц
			 String ^text = txt_Huff_ENC->Text;
			 // проверяем чтобы текст не содержал ничего кроме "0" и "1"
			 for(int i = 0; i < text->Length; i++)
			 {
				 if(text[i] != '0' && text[i] != '1')
				 {
					 MessageBox::Show("Тект кодировки содержит не допустимый текст !" + Environment::NewLine + "Формат: \"0\" и \"1\"");
					 return;
				 }
			 }
			 // Строим таблицу
			 array<String^> ^tab_text = txt_Huff_TAB->Text->Split('\n');
			 Dictionary<String^, Char> ^table = gcnew Dictionary<String^, Char>();
			 for (int i = 0; i < tab_text->Length; i++)
			 {
		 		 array<String^> ^cur = tab_text[i]->Split('\t');
	 			 if(cur[0]->Length > 1)
 				 {
					 MessageBox::Show("Некорректная таблица кодов !" + Environment::NewLine + "Формат: \"символ\"[TAB]\"код\"");
					 return;
				 }
				 if(cur->Length != 0 && cur[0]->Length != 0 && cur[1]->Length != 0)
					 table->Add(cur[1], cur[0][0]);
 			 }
			 // Попытка расшифровки и вывод в поле результата
			 txt_Huff_DEC->Text = RLE_HUFF::HuffmanDecode(text, table);
		 }
private: System::Void txt_TEXT_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 // Получаем введенный текст
			 String ^text = txt_TEXT->Text;
			 // Проверка не пусто ли поле ввода
			 if(text->Length == 0)
			 {
				 btn_rle_enc->Enabled = text->Length > 0;
				 return;
			 }
			 // Проверяем чтобы были только буквы
			 for(int i = 0; i < text->Length; i++)
			 {
				 // Если найдены цифра в тексте
				 if(Char::IsDigit(text[i])) 
				 {
					 // Выключаем кнопку
					 btn_rle_enc->Enabled = false;
					 return;
				 }
			 }
			 // Проверки пройдены
			 btn_rle_enc->Enabled = true;			 
		 }

private: System::Void txt_ENCODE_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 // 
			 btn_rle_dec->Enabled = txt_ENCODE->Text->Length > 0;			 
		 }
private: System::Void txt_Huff_DEC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 btn_huf_enc->Enabled = txt_Huff_DEC->Text->Length > 0;
			 // Очищаем поле вывода битов текста
			 txt_TEXT_BIN->Clear();
			 // Получаем текст
			 String ^text = txt_Huff_DEC->Text;
			 // Строка - бинарное представление
			 String ^text_binary = "";
			 // Собираем результирующую бинарную строку 
			 for(int i = 0; i < text->Length; i++)
			 {
				 // Получаем код текущего символа
				 int cur = text[i];
				 // Добавляем строку бит
				 for(int n = 0; n < 8; n++)
				 {
					 // Проверяем каждый бит символа
					 text_binary += ((cur & (1 << (7 - n))) == 0) ? "0" : "1";
				 }
				 // Добавляем текст в поле
				 txt_TEXT_BIN->AppendText(text_binary);
				 // Обнуляем строку для след. итерации
				 text_binary = "";
			 }
			 
		 }
private: System::Void txt_Huff_ENC_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 // Проверяем есть ли текст в поле кодировки
			 btn_huf_dec->Enabled = (txt_Huff_ENC->Text->Length > 0 && txt_Huff_TAB->Text->Length > 0);
		 }
private: System::Void txt_Huff_TAB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 // Проверяем есть ли текст в поле таблицы кодов
			 btn_huf_dec->Enabled = (txt_Huff_ENC->Text->Length > 0 && txt_Huff_TAB->Text->Length > 0);
		 }
};
}
