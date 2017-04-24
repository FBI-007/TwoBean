#include "TBDownloadPage.h"

#include <QWidget>
#include <QLineEdit>
#include <QHeaderView>
#include <QTableView>
#include <QFrame>
#include <QFile>
#include <QAbstractItemView>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <qDebug>

#include "tablemodel.h"
#include "checkboxdelegate.h"
#include "mbmessagebox.h"

TBDownloadPage::TBDownloadPage(QWidget *parent)
    : MBWindow(parent)
{
    setWindowTitle(tr("Download Page"));
    setMinimumSize(360, 240);
    setMaximumSize(500, 360);

    initTableBar();

    m_pSearchLineEdit = Q_NULLPTR;
    connect(this, SIGNAL(searchClicked()), this, SLOT(showHideSearch()));

    QFile qssFile(":/qss/checkBox.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        QString qss = QLatin1String(qssFile.readAll());
        setStyleSheet(qss);
        qssFile.close();
    }
}


// tableBar
void TBDownloadPage::initTableBar()
{
    m_pTableView = new QTableView(this);
    TableModel *pModel = new TableModel(this);
    CheckBoxDelegate *pDelegate = new CheckBoxDelegate(this);

    // 设置单行选中、最后一列拉伸、表头不高亮、无边框等
    m_pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableView->horizontalHeader()->setStretchLastSection(true);
    m_pTableView->horizontalHeader()->setHighlightSections(false);
    m_pTableView->verticalHeader()->setVisible(false);
    m_pTableView->setShowGrid(false);
    m_pTableView->setFrameShape(QFrame::NoFrame);
    m_pTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    m_pTableView->setModel(pModel);
    m_pTableView->setItemDelegate(pDelegate);

    m_pLayout->addWidget(m_pTableView);


    // 加载数据、更新界面
    QList<FileRecord> recordList;
    for (int i = 0; i < 5; ++i)
    {
        FileRecord record;
        record.bChecked = false;
        record.strFilePath = QString("E:/Qt/image_%1.png").arg(i + 1);
        recordList.append(record);
    }
    pModel->updateData(recordList);
}


void TBDownloadPage::showHideSearch()
{
    switch (m_iSearchBtnDown) {
    case -1:
        m_pSearchLineEdit = new MBSearchBar(this);
        connect(m_pSearchLineEdit, SIGNAL(searchClicked()), this, SLOT(search()));
        m_pLayout->insertWidget(1, m_pSearchLineEdit);
        m_pSearchLineEdit->show();
        m_iSearchBtnDown = 1;
        break;
    case 0:
        m_pLayout->insertWidget(1, m_pSearchLineEdit);
        m_pSearchLineEdit->show();
        m_iSearchBtnDown = 1;
        break;
    case 1:
        m_pLayout->removeWidget(m_pSearchLineEdit);
        m_pSearchLineEdit->hide();
        m_iSearchBtnDown = 0;
        break;
    }
}


// slot
void TBDownloadPage::search()
{
    QString strText = m_pSearchLineEdit->text();
    if (!strText.isEmpty())
    {
        int result = MbMessageBox::showQuestion(this, "提示", "这是一个普通的提示框-Question!",
                                   QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Cancel);
        if(result == QMessageBox::StandardButton::Ok){
            qDebug() << "OK" << strText;
        }
    }
}
