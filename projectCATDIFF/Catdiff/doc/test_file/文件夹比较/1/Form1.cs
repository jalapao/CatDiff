using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TreeViewExample
{
    public partial class Form1 : Form
    {
        private bool isExpanded = true;
        public Form1()
        {
            InitializeComponent();
            //展开所有树节点
            treeView1.ExpandAll();

        }

        private void buttonExpand_Click(object sender, EventArgs e)
        {
            if (isExpanded)
            {
                treeView1.CollapseAll();
            }
            else
            {
                treeView1.ExpandAll();
            }
            isExpanded = !isExpanded;
        }

        private void buttonShow_Click(object sender, EventArgs e)
        {
            if (treeView1.SelectedNode == null)
            {
                MessageBox.Show("未选择节点");
            }
            else
            {
                MessageBox.Show("所选节点为：" + treeView1.SelectedNode.Text);
            }
        }

        private void buttonDelete_Click(object sender, EventArgs e)
        {
            if (treeView1.SelectedNode != null)
                treeView1.SelectedNode.Remove();
        }

        private void buttonSearch_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            TreeNodeCollection nodes = treeView1.Nodes;
            //遍历根节点
            foreach (TreeNode n in nodes)
            {
                //查找该节点的所有子节点包含的课程
                AddCourseToListBox(n);
            }
        }

        private void AddCourseToListBox(TreeNode treeNode)
        {
            foreach (TreeNode tn in treeNode.Nodes)
            {
                //如果是叶节点，将其添加到课程名称列表中
                //GetNodeCount(false)指只查找其一级子节点
                if (tn.GetNodeCount(false) == 0)
                {
                    listBox1.Items.Add(tn.Text);
                }
                AddCourseToListBox(tn);
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            treeView1.CheckBoxes = checkBox1.Checked;
            treeView1.ExpandAll();
            isExpanded = true;
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            labelSelected.Text = e.Node.Text;
        }
    }
}
