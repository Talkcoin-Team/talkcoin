#ifndef OVERVIEWPAGE_H
#define OVERVIEWPAGE_H

#include "walletmodel.h"
#include <QWidget>

namespace Ui {
    class OverviewPage;
}
class ClientModel;
class WalletModel;
class TxViewDelegate;
class TransactionFilterProxy;

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = 0);
    ~OverviewPage();

    void setClientModel(ClientModel *clientModel);
    void setWalletModel(WalletModel *walletModel);
    void showOutOfSyncWarning(bool fShow);

protected:
    bool eventFilter(QObject *object, QEvent *event);

public slots:
    void setBalance(qint64 balance, qint64 unconfirmedBalance, qint64 immatureBalance);

signals:
    void transactionClicked(const QModelIndex &index);

private:
    Ui::OverviewPage *ui;
    ClientModel *clientModel;
    WalletModel *walletModel;
    qint64 currentBalance;
    qint64 currentUnconfirmedBalance;
    qint64 currentImmatureBalance;

    TxViewDelegate *txdelegate;
    TransactionFilterProxy *filter;

    QTimer *t_action;
    WalletModel::EncryptionStatus status;

private slots:
    void updateDisplayUnit();
    void handleTransactionClicked(const QModelIndex &index);
    void updateAlerts(const QString &warnings);
    void showAction();
    void showChat();
    std::string getSmileys(std::string str);
    void replaceAll(std::string& str, const std::string& from, const std::string& to);

    void on_btnChatSmiley_clicked();
    void on_btnChatSend_clicked();
    void on_txtChatNick_textChanged(const QString &arg1);
    void on_txtChatMsg_textChanged(const QString &arg1);
    void on_rbChan1_clicked();
    void on_rbChan2_clicked();
    void on_btnWallet_clicked();
    void setWalletStatus();
    void on_btnExpand_clicked();
};

#endif // OVERVIEWPAGE_H
