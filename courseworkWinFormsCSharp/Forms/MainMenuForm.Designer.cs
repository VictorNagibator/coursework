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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainMenuForm));
            this.label1 = new System.Windows.Forms.Label();
            this.WorkWithDataButton = new System.Windows.Forms.Button();
            this.OpenLoggerButton = new System.Windows.Forms.Button();
            this.PlayButton = new System.Windows.Forms.Button();
            this.ExitButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.Dock = System.Windows.Forms.DockStyle.Top;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(0, 0);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(337, 46);
            this.label1.TabIndex = 0;
            this.label1.Text = "Главное меню";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // WorkWithDataButton
            // 
            this.WorkWithDataButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.WorkWithDataButton.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.WorkWithDataButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.WorkWithDataButton.Location = new System.Drawing.Point(13, 50);
            this.WorkWithDataButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.WorkWithDataButton.Name = "WorkWithDataButton";
            this.WorkWithDataButton.Size = new System.Drawing.Size(311, 83);
            this.WorkWithDataButton.TabIndex = 1;
            this.WorkWithDataButton.Text = "Работа с данными";
            this.WorkWithDataButton.UseVisualStyleBackColor = true;
            this.WorkWithDataButton.Click += new System.EventHandler(this.WorkWithDataButton_Click);
            // 
            // OpenLoggerButton
            // 
            this.OpenLoggerButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.OpenLoggerButton.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.OpenLoggerButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.OpenLoggerButton.Location = new System.Drawing.Point(13, 143);
            this.OpenLoggerButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.OpenLoggerButton.Name = "OpenLoggerButton";
            this.OpenLoggerButton.Size = new System.Drawing.Size(311, 83);
            this.OpenLoggerButton.TabIndex = 2;
            this.OpenLoggerButton.Text = "Открыть логгер";
            this.OpenLoggerButton.UseVisualStyleBackColor = true;
            this.OpenLoggerButton.Click += new System.EventHandler(this.OpenLoggerButton_Click);
            // 
            // PlayButton
            // 
            this.PlayButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.PlayButton.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.PlayButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PlayButton.Location = new System.Drawing.Point(13, 236);
            this.PlayButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.PlayButton.Name = "PlayButton";
            this.PlayButton.Size = new System.Drawing.Size(311, 83);
            this.PlayButton.TabIndex = 3;
            this.PlayButton.Text = "Играть";
            this.PlayButton.UseVisualStyleBackColor = true;
            this.PlayButton.Click += new System.EventHandler(this.PlayButton_Click);
            // 
            // ExitButton
            // 
            this.ExitButton.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ExitButton.FlatStyle = System.Windows.Forms.FlatStyle.Popup;
            this.ExitButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.ExitButton.Location = new System.Drawing.Point(13, 329);
            this.ExitButton.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(311, 83);
            this.ExitButton.TabIndex = 4;
            this.ExitButton.Text = "Выйти";
            this.ExitButton.UseVisualStyleBackColor = true;
            this.ExitButton.Click += new System.EventHandler(this.ExitButton_Click);
            // 
            // MainMenuForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(337, 425);
            this.Controls.Add(this.ExitButton);
            this.Controls.Add(this.PlayButton);
            this.Controls.Add(this.OpenLoggerButton);
            this.Controls.Add(this.WorkWithDataButton);
            this.Controls.Add(this.label1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "MainMenuForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Курсач++";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button WorkWithDataButton;
        private System.Windows.Forms.Button OpenLoggerButton;
        private System.Windows.Forms.Button PlayButton;
        private System.Windows.Forms.Button ExitButton;
    }
}