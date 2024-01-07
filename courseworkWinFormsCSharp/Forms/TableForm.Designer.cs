namespace courseworkWinFormsCSharp.Forms
{
    partial class TableForm
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
            this.MenuStrip = new System.Windows.Forms.MenuStrip();
            this.выбратьФайлToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.работаСДаннымиToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.игратьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.выйтиВГлавноеМенюToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dataGridView = new System.Windows.Forms.DataGridView();
            this.IDColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.LaptopColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.StatusColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.добавитьЗаписьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.изменитьЗаписьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.удалитьЗаписьToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
            this.SuspendLayout();
            // 
            // MenuStrip
            // 
            this.MenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.выбратьФайлToolStripMenuItem,
            this.работаСДаннымиToolStripMenuItem,
            this.игратьToolStripMenuItem,
            this.выйтиВГлавноеМенюToolStripMenuItem});
            this.MenuStrip.Location = new System.Drawing.Point(0, 0);
            this.MenuStrip.Name = "MenuStrip";
            this.MenuStrip.Size = new System.Drawing.Size(800, 24);
            this.MenuStrip.TabIndex = 0;
            this.MenuStrip.Text = "MenuStrip";
            // 
            // выбратьФайлToolStripMenuItem
            // 
            this.выбратьФайлToolStripMenuItem.Name = "выбратьФайлToolStripMenuItem";
            this.выбратьФайлToolStripMenuItem.Size = new System.Drawing.Size(98, 20);
            this.выбратьФайлToolStripMenuItem.Text = "Выбрать файл";
            this.выбратьФайлToolStripMenuItem.Click += new System.EventHandler(this.выбратьФайлToolStripMenuItem_Click);
            // 
            // работаСДаннымиToolStripMenuItem
            // 
            this.работаСДаннымиToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.добавитьЗаписьToolStripMenuItem,
            this.изменитьЗаписьToolStripMenuItem,
            this.удалитьЗаписьToolStripMenuItem});
            this.работаСДаннымиToolStripMenuItem.Enabled = false;
            this.работаСДаннымиToolStripMenuItem.Name = "работаСДаннымиToolStripMenuItem";
            this.работаСДаннымиToolStripMenuItem.Size = new System.Drawing.Size(120, 20);
            this.работаСДаннымиToolStripMenuItem.Text = "Работа с данными";
            // 
            // игратьToolStripMenuItem
            // 
            this.игратьToolStripMenuItem.Name = "игратьToolStripMenuItem";
            this.игратьToolStripMenuItem.Size = new System.Drawing.Size(57, 20);
            this.игратьToolStripMenuItem.Text = "Играть";
            this.игратьToolStripMenuItem.Click += new System.EventHandler(this.игратьToolStripMenuItem_Click);
            // 
            // выйтиВГлавноеМенюToolStripMenuItem
            // 
            this.выйтиВГлавноеМенюToolStripMenuItem.Name = "выйтиВГлавноеМенюToolStripMenuItem";
            this.выйтиВГлавноеМенюToolStripMenuItem.Size = new System.Drawing.Size(145, 20);
            this.выйтиВГлавноеМенюToolStripMenuItem.Text = "Выйти в главное меню";
            this.выйтиВГлавноеМенюToolStripMenuItem.Click += new System.EventHandler(this.выйтиВГлавноеМенюToolStripMenuItem_Click);
            // 
            // dataGridView
            // 
            this.dataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.IDColumn,
            this.LaptopColumn,
            this.StatusColumn});
            this.dataGridView.Location = new System.Drawing.Point(12, 27);
            this.dataGridView.Name = "dataGridView";
            this.dataGridView.ReadOnly = true;
            this.dataGridView.Size = new System.Drawing.Size(776, 411);
            this.dataGridView.TabIndex = 1;
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
            // добавитьЗаписьToolStripMenuItem
            // 
            this.добавитьЗаписьToolStripMenuItem.Name = "добавитьЗаписьToolStripMenuItem";
            this.добавитьЗаписьToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.добавитьЗаписьToolStripMenuItem.Text = "Добавить запись";
            this.добавитьЗаписьToolStripMenuItem.Click += new System.EventHandler(this.добавитьЗаписьToolStripMenuItem_Click);
            // 
            // изменитьЗаписьToolStripMenuItem
            // 
            this.изменитьЗаписьToolStripMenuItem.Name = "изменитьЗаписьToolStripMenuItem";
            this.изменитьЗаписьToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.изменитьЗаписьToolStripMenuItem.Text = "Изменить запись";
            // 
            // удалитьЗаписьToolStripMenuItem
            // 
            this.удалитьЗаписьToolStripMenuItem.Name = "удалитьЗаписьToolStripMenuItem";
            this.удалитьЗаписьToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.удалитьЗаписьToolStripMenuItem.Text = "Удалить запись";
            // 
            // TableForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.dataGridView);
            this.Controls.Add(this.MenuStrip);
            this.MainMenuStrip = this.MenuStrip;
            this.Name = "TableForm";
            this.Text = "Работа с данными";
            this.MenuStrip.ResumeLayout(false);
            this.MenuStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip MenuStrip;
        private System.Windows.Forms.ToolStripMenuItem выбратьФайлToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem работаСДаннымиToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem игратьToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem выйтиВГлавноеМенюToolStripMenuItem;
        private System.Windows.Forms.DataGridView dataGridView;
        private System.Windows.Forms.DataGridViewTextBoxColumn IDColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn LaptopColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn StatusColumn;
        private System.Windows.Forms.ToolStripMenuItem добавитьЗаписьToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem изменитьЗаписьToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem удалитьЗаписьToolStripMenuItem;
    }
}