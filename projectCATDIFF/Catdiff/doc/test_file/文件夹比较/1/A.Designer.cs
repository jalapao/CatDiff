namespace TreeViewExample
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.TreeNode treeNode1 = new System.Windows.Forms.TreeNode("操作系统", 3, 3);
            System.Windows.Forms.TreeNode treeNode2 = new System.Windows.Forms.TreeNode("编译原理", 3, 3);
            System.Windows.Forms.TreeNode treeNode3 = new System.Windows.Forms.TreeNode("数据库原理", 3, 3);
            System.Windows.Forms.TreeNode treeNode4 = new System.Windows.Forms.TreeNode("计算机技术专业", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode1,
            treeNode2,
            treeNode3});
            System.Windows.Forms.TreeNode treeNode5 = new System.Windows.Forms.TreeNode("管理学原理", 3, 3);
            System.Windows.Forms.TreeNode treeNode6 = new System.Windows.Forms.TreeNode("统计学", 3, 3);
            System.Windows.Forms.TreeNode treeNode7 = new System.Windows.Forms.TreeNode("管理信息系统", 3, 3);
            System.Windows.Forms.TreeNode treeNode8 = new System.Windows.Forms.TreeNode("信息管理与信息系统专业", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode5,
            treeNode6,
            treeNode7});
            System.Windows.Forms.TreeNode treeNode9 = new System.Windows.Forms.TreeNode("信息学院", 1, 1, new System.Windows.Forms.TreeNode[] {
            treeNode4,
            treeNode8});
            System.Windows.Forms.TreeNode treeNode10 = new System.Windows.Forms.TreeNode("数学分析", 3, 3);
            System.Windows.Forms.TreeNode treeNode11 = new System.Windows.Forms.TreeNode("高等代数", 3, 3);
            System.Windows.Forms.TreeNode treeNode12 = new System.Windows.Forms.TreeNode("常微分方程", 3, 3);
            System.Windows.Forms.TreeNode treeNode13 = new System.Windows.Forms.TreeNode("基础数学专业", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode10,
            treeNode11,
            treeNode12});
            System.Windows.Forms.TreeNode treeNode14 = new System.Windows.Forms.TreeNode("复变函数", 3, 3);
            System.Windows.Forms.TreeNode treeNode15 = new System.Windows.Forms.TreeNode("离散数学", 3, 3);
            System.Windows.Forms.TreeNode treeNode16 = new System.Windows.Forms.TreeNode("数学模型", 3, 3);
            System.Windows.Forms.TreeNode treeNode17 = new System.Windows.Forms.TreeNode("应用数学专业", 2, 2, new System.Windows.Forms.TreeNode[] {
            treeNode14,
            treeNode15,
            treeNode16});
            System.Windows.Forms.TreeNode treeNode18 = new System.Windows.Forms.TreeNode("数学学院", 1, 1, new System.Windows.Forms.TreeNode[] {
            treeNode13,
            treeNode17});
            System.Windows.Forms.TreeNode treeNode19 = new System.Windows.Forms.TreeNode("课程信息", new System.Windows.Forms.TreeNode[] {
            treeNode9,
            treeNode18});
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.buttonSearch = new System.Windows.Forms.Button();
            this.buttonExpand = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.labelSelected = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonDelete = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // treeView1
            // 
            this.treeView1.ImageIndex = 0;
            this.treeView1.ImageList = this.imageList1;
            this.treeView1.Location = new System.Drawing.Point(12, 12);
            this.treeView1.Name = "treeView1";
            treeNode1.ImageIndex = 3;
            treeNode1.Name = "Node7";
            treeNode1.SelectedImageIndex = 3;
            treeNode1.Text = "操作系统";
            treeNode2.ImageIndex = 3;
            treeNode2.Name = "Node8";
            treeNode2.SelectedImageIndex = 3;
            treeNode2.Text = "编译原理";
            treeNode3.ImageIndex = 3;
            treeNode3.Name = "Node9";
            treeNode3.SelectedImageIndex = 3;
            treeNode3.Text = "数据库原理";
            treeNode4.ImageIndex = 2;
            treeNode4.Name = "Node2";
            treeNode4.SelectedImageIndex = 2;
            treeNode4.Text = "计算机技术专业";
            treeNode5.ImageIndex = 3;
            treeNode5.Name = "Node10";
            treeNode5.SelectedImageIndex = 3;
            treeNode5.Text = "管理学原理";
            treeNode6.ImageIndex = 3;
            treeNode6.Name = "Node11";
            treeNode6.SelectedImageIndex = 3;
            treeNode6.Text = "统计学";
            treeNode7.ImageIndex = 3;
            treeNode7.Name = "Node12";
            treeNode7.SelectedImageIndex = 3;
            treeNode7.Text = "管理信息系统";
            treeNode8.ImageIndex = 2;
            treeNode8.Name = "Node4";
            treeNode8.SelectedImageIndex = 2;
            treeNode8.Text = "信息管理与信息系统专业";
            treeNode9.ImageIndex = 1;
            treeNode9.Name = "Node1";
            treeNode9.SelectedImageIndex = 1;
            treeNode9.Text = "信息学院";
            treeNode10.ImageIndex = 3;
            treeNode10.Name = "Node13";
            treeNode10.SelectedImageIndex = 3;
            treeNode10.Text = "数学分析";
            treeNode11.ImageIndex = 3;
            treeNode11.Name = "Node14";
            treeNode11.SelectedImageIndex = 3;
            treeNode11.Text = "高等代数";
            treeNode12.ImageIndex = 3;
            treeNode12.Name = "Node15";
            treeNode12.SelectedImageIndex = 3;
            treeNode12.Text = "常微分方程";
            treeNode13.ImageIndex = 2;
            treeNode13.Name = "Node5";
            treeNode13.SelectedImageIndex = 2;
            treeNode13.Text = "基础数学专业";
            treeNode14.ImageIndex = 3;
            treeNode14.Name = "Node16";
            treeNode14.SelectedImageIndex = 3;
            treeNode14.Text = "复变函数";
            treeNode15.ImageIndex = 3;
            treeNode15.Name = "Node17";
            treeNode15.SelectedImageIndex = 3;
            treeNode15.Text = "离散数学";
            treeNode16.ImageIndex = 3;
            treeNode16.Name = "Node18";
            treeNode16.SelectedImageIndex = 3;
            treeNode16.Text = "数学模型";
            treeNode17.ImageIndex = 2;
            treeNode17.Name = "Node6";
            treeNode17.SelectedImageIndex = 2;
            treeNode17.Text = "应用数学专业";
            treeNode18.ImageIndex = 1;
            treeNode18.Name = "Node3";
            treeNode18.SelectedImageIndex = 1;
            treeNode18.Text = "数学学院";
            treeNode19.Name = "Node0";
            treeNode19.Text = "课程信息";
            this.treeView1.Nodes.AddRange(new System.Windows.Forms.TreeNode[] {
            treeNode19});
            this.treeView1.SelectedImageIndex = 0;
            this.treeView1.Size = new System.Drawing.Size(233, 323);
            this.treeView1.TabIndex = 1;
            this.treeView1.AfterSelect += new System.Windows.Forms.TreeViewEventHandler(this.treeView1_AfterSelect);
            // 
            // imageList1
            // 
            this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            this.imageList1.Images.SetKeyName(0, "N01.gif");
            this.imageList1.Images.SetKeyName(1, "N02.gif");
            this.imageList1.Images.SetKeyName(2, "N03.gif");
            this.imageList1.Images.SetKeyName(3, "N04.gif");
            // 
            // buttonSearch
            // 
            this.buttonSearch.Location = new System.Drawing.Point(280, 86);
            this.buttonSearch.Name = "buttonSearch";
            this.buttonSearch.Size = new System.Drawing.Size(174, 22);
            this.buttonSearch.TabIndex = 8;
            this.buttonSearch.Text = "搜索所有课程";
            this.buttonSearch.UseVisualStyleBackColor = true;
            this.buttonSearch.Click += new System.EventHandler(this.buttonSearch_Click);
            // 
            // buttonExpand
            // 
            this.buttonExpand.Location = new System.Drawing.Point(280, 50);
            this.buttonExpand.Name = "buttonExpand";
            this.buttonExpand.Size = new System.Drawing.Size(174, 22);
            this.buttonExpand.TabIndex = 7;
            this.buttonExpand.Text = "折叠/展开所有课程目录";
            this.buttonExpand.UseVisualStyleBackColor = true;
            this.buttonExpand.Click += new System.EventHandler(this.buttonExpand_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.listBox1);
            this.groupBox1.Location = new System.Drawing.Point(280, 121);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(174, 136);
            this.groupBox1.TabIndex = 11;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "检索结果";
            // 
            // checkBox1
            // 
            this.checkBox1.AutoSize = true;
            this.checkBox1.Location = new System.Drawing.Point(280, 15);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(96, 16);
            this.checkBox1.TabIndex = 12;
            this.checkBox1.Text = "节点带复选框";
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // listBox1
            // 
            this.listBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 12;
            this.listBox1.Location = new System.Drawing.Point(3, 17);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(168, 112);
            this.listBox1.TabIndex = 11;
            // 
            // labelSelected
            // 
            this.labelSelected.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.labelSelected.Location = new System.Drawing.Point(345, 280);
            this.labelSelected.Name = "labelSelected";
            this.labelSelected.Size = new System.Drawing.Size(100, 23);
            this.labelSelected.TabIndex = 17;
            this.labelSelected.Text = "labelSelected";
            this.labelSelected.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(277, 286);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 12);
            this.label1.TabIndex = 16;
            this.label1.Text = "当前节点：";
            // 
            // buttonDelete
            // 
            this.buttonDelete.Location = new System.Drawing.Point(279, 313);
            this.buttonDelete.Name = "buttonDelete";
            this.buttonDelete.Size = new System.Drawing.Size(172, 22);
            this.buttonDelete.TabIndex = 15;
            this.buttonDelete.Text = "删除选定节点";
            this.buttonDelete.UseVisualStyleBackColor = true;
            this.buttonDelete.Click += new System.EventHandler(this.buttonDelete_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(467, 350);
            this.Controls.Add(this.labelSelected);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.buttonDelete);
            this.Controls.Add(this.checkBox1);
            this.Controls.Add(this.buttonSearch);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.buttonExpand);
            this.Controls.Add(this.treeView1);
            this.Name = "Form1";
            this.Text = "TreeView用法举例";
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.ImageList imageList1;
        private System.Windows.Forms.Button buttonSearch;
        private System.Windows.Forms.Button buttonExpand;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Label labelSelected;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button buttonDelete;
    }
}

