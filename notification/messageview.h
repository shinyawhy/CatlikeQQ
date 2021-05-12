#ifndef MESSAGEEDIT_H
#define MESSAGEEDIT_H

#include <QTextBrowser>
#include <QLabel>
#include "msgbean.h"

#define MESSAGE_LABEL

class MessageView : public QLabel
{
    Q_OBJECT
public:
    explicit MessageView(QWidget *parent = nullptr);

    void setMessage(const MsgBean &msg);

    QSize adjustSizeByTextWidth(int w);

    void setTextColor(QColor c);

signals:
    void needMemberNames();

public slots:
    void replaceGroupAt();

private:
    MsgBean msg;
};

#endif // MESSAGEEDIT_H
