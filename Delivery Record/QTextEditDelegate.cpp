#include "stdafx.h"
#include "QTextEditDelegate.h"

QTextEditDelegate::QTextEditDelegate(QWidget *parent, const QString  &InputMask,const QStringList  &PreInputContents, bool IsEnableClearButton)
	: QItemDelegate(parent), m_InputMask(InputMask), m_PreInputContents(PreInputContents),
	  m_ClearButtonIsEnable(IsEnableClearButton)
{
	
}

QTextEditDelegate::~QTextEditDelegate()
{

}

QWidget * QTextEditDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	 
	QTextEdit *editor = new QTextEdit(parent);
	editor->setPlaceholderText(m_InputMask);
	//editor->setValidator(m_InputValidator);
	//editor->setAlignment(Qt::AlignCenter);
	editor->setStyleSheet("background-color:rgba(193, 205, 205)");
	editor->setFontPointSize(10);
	editor->setAcceptRichText(true);
	/*if (m_PreInputContents.length()!=0)
	{
		QCompleter *MyInfor = new QCompleter(m_PreInputContents);
		editor->setCompleter(MyInfor);
	}*/
	/*if (m_ClearButtonIsEnable)
	{
		
		editor->setClearButtonEnabled(true);
	}*/
	
	return editor;
}

void QTextEditDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
	QString value = index.model()->data(index, Qt::EditRole).toString();
	QTextEdit *textEditor = static_cast<QTextEdit*>(editor);
	/*textEditor->setClearButtonEnabled(true);*/
	textEditor->setText(value);
}

void QTextEditDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
	QTextEdit *textEditor = static_cast<QTextEdit*>(editor);
	QString value = textEditor->toPlainText();
	model->setData(index, value, Qt::EditRole);
}

void QTextEditDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
	editor->setGeometry(option.rect);
}
