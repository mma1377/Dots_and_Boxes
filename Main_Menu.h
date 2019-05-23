#pragma once
#include "Game_Table.h"

namespace Dots_and_Boxes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Main_Menu : public System::Windows::Forms::Form
	{
	public:
		Main_Menu(void);


	protected:

		~Main_Menu();


	private: System::Windows::Forms::Button^  start_game_btn;
	private: System::Windows::Forms::RadioButton^  player_start_first_radio;
	private: System::Windows::Forms::RadioButton^  bot_start_first_radio;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  game_size_track_bar;
	private: System::Windows::Forms::Button^  change_color_btn;



	private: bool is_player_red;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;





	private:
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->start_game_btn = (gcnew System::Windows::Forms::Button());
			this->player_start_first_radio = (gcnew System::Windows::Forms::RadioButton());
			this->bot_start_first_radio = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->game_size_track_bar = (gcnew System::Windows::Forms::TrackBar());
			this->change_color_btn = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->game_size_track_bar))->BeginInit();
			this->SuspendLayout();
			// 
			// start_game_btn
			// 
			this->start_game_btn->Cursor = System::Windows::Forms::Cursors::Default;
			this->start_game_btn->Location = System::Drawing::Point(171, 218);
			this->start_game_btn->Name = L"start_game_btn";
			this->start_game_btn->Size = System::Drawing::Size(101, 31);
			this->start_game_btn->TabIndex = 0;
			this->start_game_btn->Text = L"Let\'s Play";
			this->start_game_btn->UseVisualStyleBackColor = true;
			this->start_game_btn->Click += gcnew System::EventHandler(this, &Main_Menu::start_game_btn_Click);
			// 
			// player_start_first_radio
			// 
			this->player_start_first_radio->AutoSize = true;
			this->player_start_first_radio->Checked = true;
			this->player_start_first_radio->ForeColor = System::Drawing::Color::RoyalBlue;
			this->player_start_first_radio->Location = System::Drawing::Point(16, 132);
			this->player_start_first_radio->Name = L"player_start_first_radio";
			this->player_start_first_radio->Size = System::Drawing::Size(54, 17);
			this->player_start_first_radio->TabIndex = 1;
			this->player_start_first_radio->TabStop = true;
			this->player_start_first_radio->Text = L"Player";
			this->player_start_first_radio->UseVisualStyleBackColor = true;
			// 
			// bot_start_first_radio
			// 
			this->bot_start_first_radio->AutoSize = true;
			this->bot_start_first_radio->ForeColor = System::Drawing::Color::Tomato;
			this->bot_start_first_radio->Location = System::Drawing::Point(16, 155);
			this->bot_start_first_radio->Name = L"bot_start_first_radio";
			this->bot_start_first_radio->Size = System::Drawing::Size(41, 17);
			this->bot_start_first_radio->TabIndex = 2;
			this->bot_start_first_radio->Text = L"Bot";
			this->bot_start_first_radio->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Who will start the game\?";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 47);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Game Size";
			// 
			// game_size_track_bar
			// 
			this->game_size_track_bar->Location = System::Drawing::Point(92, 36);
			this->game_size_track_bar->Minimum = 1;
			this->game_size_track_bar->Name = L"game_size_track_bar";
			this->game_size_track_bar->Size = System::Drawing::Size(104, 45);
			this->game_size_track_bar->TabIndex = 5;
			this->game_size_track_bar->Value = 1;
			// 
			// change_color_btn
			// 
			this->change_color_btn->Location = System::Drawing::Point(12, 178);
			this->change_color_btn->Name = L"change_color_btn";
			this->change_color_btn->Size = System::Drawing::Size(104, 28);
			this->change_color_btn->TabIndex = 6;
			this->change_color_btn->Text = L"Change color";
			this->change_color_btn->UseVisualStyleBackColor = true;
			this->change_color_btn->Click += gcnew System::EventHandler(this, &Main_Menu::change_color_btn_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->label3->Location = System::Drawing::Point(9, 287);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 15);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Developed By:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->label4->Location = System::Drawing::Point(104, 287);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(146, 15);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Mohammadmahdi Alijani";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->label5->Location = System::Drawing::Point(104, 312);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(83, 15);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Somaye Amiri";
			// 
			// Main_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(284, 358);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->change_color_btn);
			this->Controls->Add(this->game_size_track_bar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bot_start_first_radio);
			this->Controls->Add(this->player_start_first_radio);
			this->Controls->Add(this->start_game_btn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Main_Menu";
			this->Text = L"Dots & Boxes - Algorithm Design Project ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->game_size_track_bar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void start_game_btn_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void change_color_btn_Click(System::Object^  sender, System::EventArgs^  e);
	};
}

