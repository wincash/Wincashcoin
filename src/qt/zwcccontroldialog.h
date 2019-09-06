// Copyright (c) 2017-2018 The WINCASHCOIN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZWCCCONTROLDIALOG_H
#define ZWCCCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zwcc/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZWccControlDialog;
}

class CZWccControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZWccControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZWccControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZWccControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZWccControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZWccControlDialog(QWidget *parent);
    ~ZWccControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZWccControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZWccControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZWCCCONTROLDIALOG_H
