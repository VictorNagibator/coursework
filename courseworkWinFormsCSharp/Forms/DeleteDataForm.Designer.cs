namespace courseworkWinFormsCSharp.Forms
{
    partial class DeleteDataForm
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
            this.OrderDataGridView = new System.Windows.Forms.DataGridView();
            this.IDColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.LaptopColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.StatusColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.LaptopDataGridView = new System.Windows.Forms.DataGridView();
            this.IDLabel = new System.Windows.Forms.Label();
            this.OrderInfoLabel = new System.Windows.Forms.Label();
            this.LaptopInfoLabel = new System.Windows.Forms.Label();
            this.DeleteDataButton = new System.Windows.Forms.Button();
            this.CloseButton = new System.Windows.Forms.Button();
            this.PossibleIDsListBox = new System.Windows.Forms.ListBox();
            this.Column1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Column7 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.OrderDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.LaptopDataGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // OrderDataGridView
            // 
            this.OrderDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.IDColumn,
            this.LaptopColumn,
            this.StatusColumn});
            this.OrderDataGridView.Location = new System.Drawing.Point(185, 85);
            this.OrderDataGridView.Name = "OrderDataGridView";
            this.OrderDataGridView.ReadOnly = true;
            this.OrderDataGridView.Size = new System.Drawing.Size(538, 45);
            this.OrderDataGridView.TabIndex = 2;
            // 
            // IDColumn
            // 
            this.IDColumn.HeaderText = "ID";
            this.IDColumn.Name = "IDColumn";
            this.IDColumn.ReadOnly = true;
            this.IDColumn.Width = 125;
            // 
            // LaptopColumn
            // 
            this.LaptopColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.LaptopColumn.HeaderText = "Ноутбук";
            this.LaptopColumn.Name = "LaptopColumn";
            this.LaptopColumn.ReadOnly = true;
            // 
            // StatusColumn
            // 
            this.StatusColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.StatusColumn.HeaderText = "Статус заказа";
            this.StatusColumn.Name = "StatusColumn";
            this.StatusColumn.ReadOnly = true;
            // 
            // LaptopDataGridView
            // 
            this.LaptopDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.LaptopDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Column1,
            this.Column2,
            this.Column3,
            this.Column4,
            this.Column5,
            this.Column6,
            this.Column7});
            this.LaptopDataGridView.Location = new System.Drawing.Point(13, 176);
            this.LaptopDataGridView.Name = "LaptopDataGridView";
            this.LaptopDataGridView.ReadOnly = true;
            this.LaptopDataGridView.Size = new System.Drawing.Size(866, 57);
            this.LaptopDataGridView.TabIndex = 3;
            // 
            // IDLabel
            // 
            this.IDLabel.AutoSize = true;
            this.IDLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.IDLabel.Location = new System.Drawing.Point(290, 9);
            this.IDLabel.Name = "IDLabel";
            this.IDLabel.Size = new System.Drawing.Size(229, 25);
            this.IDLabel.TabIndex = 5;
            this.IDLabel.Text = "ID удаляемой записи:";
            // 
            // OrderInfoLabel
            // 
            this.OrderInfoLabel.AutoSize = true;
            this.OrderInfoLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.OrderInfoLabel.Location = new System.Drawing.Point(335, 58);
            this.OrderInfoLabel.Name = "OrderInfoLabel";
            this.OrderInfoLabel.Size = new System.Drawing.Size(206, 24);
            this.OrderInfoLabel.TabIndex = 6;
            this.OrderInfoLabel.Text = "Информация о заказе";
            // 
            // LaptopInfoLabel
            // 
            this.LaptopInfoLabel.AutoSize = true;
            this.LaptopInfoLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LaptopInfoLabel.Location = new System.Drawing.Point(335, 149);
            this.LaptopInfoLabel.Name = "LaptopInfoLabel";
            this.LaptopInfoLabel.Size = new System.Drawing.Size(227, 24);
            this.LaptopInfoLabel.TabIndex = 7;
            this.LaptopInfoLabel.Text = "Информация о ноутбуке";
            // 
            // DeleteDataButton
            // 
            this.DeleteDataButton.Enabled = false;
            this.DeleteDataButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.DeleteDataButton.Location = new System.Drawing.Point(323, 276);
            this.DeleteDataButton.Name = "DeleteDataButton";
            this.DeleteDataButton.Size = new System.Drawing.Size(126, 48);
            this.DeleteDataButton.TabIndex = 9;
            this.DeleteDataButton.Text = "Удалить";
            this.DeleteDataButton.UseVisualStyleBackColor = true;
            this.DeleteDataButton.Click += new System.EventHandler(this.DeleteDataButton_Click);
            // 
            // CloseButton
            // 
            this.CloseButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.CloseButton.Location = new System.Drawing.Point(455, 276);
            this.CloseButton.Name = "CloseButton";
            this.CloseButton.Size = new System.Drawing.Size(126, 48);
            this.CloseButton.TabIndex = 8;
            this.CloseButton.Text = "Закрыть";
            this.CloseButton.UseVisualStyleBackColor = true;
            this.CloseButton.Click += new System.EventHandler(this.CloseButton_Click);
            // 
            // PossibleIDsListBox
            // 
            this.PossibleIDsListBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PossibleIDsListBox.FormattingEnabled = true;
            this.PossibleIDsListBox.ItemHeight = 25;
            this.PossibleIDsListBox.Location = new System.Drawing.Point(525, 9);
            this.PossibleIDsListBox.Name = "PossibleIDsListBox";
            this.PossibleIDsListBox.Size = new System.Drawing.Size(88, 29);
            this.PossibleIDsListBox.TabIndex = 10;
            this.PossibleIDsListBox.SelectedIndexChanged += new System.EventHandler(this.PossibleIDsListBox_SelectedIndexChanged);
            // 
            // Column1
            // 
            this.Column1.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.Column1.HeaderText = "Название модели";
            this.Column1.Name = "Column1";
            this.Column1.ReadOnly = true;
            // 
            // Column2
            // 
            this.Column2.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.Column2.HeaderText = "CPU";
            this.Column2.Name = "Column2";
            this.Column2.ReadOnly = true;
            // 
            // Column3
            // 
            this.Column3.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.Column3.HeaderText = "GPU";
            this.Column3.Name = "Column3";
            this.Column3.ReadOnly = true;
            // 
            // Column4
            // 
            this.Column4.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.Column4.HeaderText = "RAM";
            this.Column4.Name = "Column4";
            this.Column4.ReadOnly = true;
            // 
            // Column5
            // 
            this.Column5.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.Column5.HeaderText = "Материнская плата";
            this.Column5.Name = "Column5";
            this.Column5.ReadOnly = true;
            // 
            // Column6
            // 
            this.Column6.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.Column6.HeaderText = "Экран";
            this.Column6.Name = "Column6";
            this.Column6.ReadOnly = true;
            // 
            // Column7
            // 
            this.Column7.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.Column7.HeaderText = "Хранилище данных";
            this.Column7.Name = "Column7";
            this.Column7.ReadOnly = true;
            // 
            // DeleteDataForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(891, 336);
            this.Controls.Add(this.PossibleIDsListBox);
            this.Controls.Add(this.DeleteDataButton);
            this.Controls.Add(this.CloseButton);
            this.Controls.Add(this.LaptopInfoLabel);
            this.Controls.Add(this.OrderInfoLabel);
            this.Controls.Add(this.IDLabel);
            this.Controls.Add(this.LaptopDataGridView);
            this.Controls.Add(this.OrderDataGridView);
            this.Name = "DeleteDataForm";
            this.Text = "Удалить запись";
            ((System.ComponentModel.ISupportInitialize)(this.OrderDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.LaptopDataGridView)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView OrderDataGridView;
        private System.Windows.Forms.DataGridViewTextBoxColumn IDColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn LaptopColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn StatusColumn;
        private System.Windows.Forms.DataGridView LaptopDataGridView;
        private System.Windows.Forms.Label IDLabel;
        private System.Windows.Forms.Label OrderInfoLabel;
        private System.Windows.Forms.Label LaptopInfoLabel;
        private System.Windows.Forms.Button DeleteDataButton;
        private System.Windows.Forms.Button CloseButton;
        private System.Windows.Forms.ListBox PossibleIDsListBox;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column1;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column2;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column3;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column4;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column5;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column6;
        private System.Windows.Forms.DataGridViewTextBoxColumn Column7;
    }
}