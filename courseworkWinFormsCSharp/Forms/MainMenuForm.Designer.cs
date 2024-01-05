namespace courseworkWinFormsCSharp
{
    partial class MainMenuForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.WorkWithDataButton = new System.Windows.Forms.Button();
            this.OpenLoggerButton = new System.Windows.Forms.Button();
            this.PlayButton = new System.Windows.Forms.Button();
            this.ExitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(165, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(213, 37);
            this.label1.TabIndex = 0;
            this.label1.Text = "Главное меню";
            // 
            // WorkWithDataButton
            // 
            this.WorkWithDataButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.WorkWithDataButton.Location = new System.Drawing.Point(160, 100);
            this.WorkWithDataButton.Name = "WorkWithDataButton";
            this.WorkWithDataButton.Size = new System.Drawing.Size(230, 69);
            this.WorkWithDataButton.TabIndex = 1;
            this.WorkWithDataButton.Text = "Работа с данными";
            this.WorkWithDataButton.UseVisualStyleBackColor = true;
            // 
            // OpenLoggerButton
            // 
            this.OpenLoggerButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.OpenLoggerButton.Location = new System.Drawing.Point(160, 175);
            this.OpenLoggerButton.Name = "OpenLoggerButton";
            this.OpenLoggerButton.Size = new System.Drawing.Size(230, 69);
            this.OpenLoggerButton.TabIndex = 2;
            this.OpenLoggerButton.Text = "Открыть логгер";
            this.OpenLoggerButton.UseVisualStyleBackColor = true;
            this.OpenLoggerButton.Click += new System.EventHandler(this.OpenLoggerButton_Click);
            // 
            // PlayButton
            // 
            this.PlayButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PlayButton.Location = new System.Drawing.Point(160, 250);
            this.PlayButton.Name = "PlayButton";
            this.PlayButton.Size = new System.Drawing.Size(230, 69);
            this.PlayButton.TabIndex = 3;
            this.PlayButton.Text = "Играть";
            this.PlayButton.UseVisualStyleBackColor = true;
            this.PlayButton.Click += new System.EventHandler(this.PlayButton_Click);
            // 
            // ExitButton
            // 
            this.ExitButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ExitButton.Location = new System.Drawing.Point(160, 325);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(230, 69);
            this.ExitButton.TabIndex = 4;
            this.ExitButton.Text = "Выйти";
            this.ExitButton.UseVisualStyleBackColor = true;
            this.ExitButton.Click += new System.EventHandler(this.ExitButton_Click);
            // 
            // MainMenuForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(555, 406);
            this.Controls.Add(this.ExitButton);
            this.Controls.Add(this.PlayButton);
            this.Controls.Add(this.OpenLoggerButton);
            this.Controls.Add(this.WorkWithDataButton);
            this.Controls.Add(this.label1);
            this.Name = "MainMenuForm";
            this.Text = "Главное меню";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button WorkWithDataButton;
        private System.Windows.Forms.Button OpenLoggerButton;
        private System.Windows.Forms.Button PlayButton;
        private System.Windows.Forms.Button ExitButton;
    }
}