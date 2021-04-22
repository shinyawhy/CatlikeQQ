#ifndef NOTIFICATIONCARD_H
#define NOTIFICATIONCARD_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsDropShadowEffect>
#include "interactivebuttonbase.h"
#include "msgbean.h"
#include "global.h"

#define CREATE_SHADOW(x)                                                  \
do {                                                                      \
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect(x); \
    effect->setOffset(3, 3);                                              \
    effect->setBlurRadius(12);                                            \
    effect->setColor(QColor(128, 128, 128, 128));                         \
    x->setGraphicsEffect(effect);                                         \
} while(0)

namespace Ui {
class NotificationCard;
}

class NotificationCard : public QWidget
{
    Q_OBJECT

public:
    explicit NotificationCard(QWidget *parent = nullptr);
    ~NotificationCard() override;

    void showFrom(QPoint hi, QPoint sh);

    void setMsg(const MsgBean& msg);
    int append(const MsgBean& msg);

    bool isHidding() const;

signals:
    void signalToHide();
    void signalHided();

private slots:
    void toHide();

protected:
    void showEvent(QShowEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::NotificationCard *ui;

    qint64 userId = 0;
    qint64 groupId = 0;
    QList<MsgBean> msgs; // 可能会合并多条消息
    QString showText;

    InteractiveButtonBase* bg;
    QPoint hidePoint;
    QTimer* displayTimer;
    bool hidding = false;
};

#endif // NOTIFICATIONCARD_H
