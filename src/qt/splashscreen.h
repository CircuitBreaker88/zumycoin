// Copyright (c) 2009-2018 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Developers
// Copyright (c) 2014-2018 The Dash Core Developers
// Copyright (c) 2016-2018 Duality Blockchain Solutions Developers
// Copyright (c) 2017-2018 Zumy Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZUMY_QT_SPLASHSCREEN_H
#define ZUMY_QT_SPLASHSCREEN_H

#include <QSplashScreen>

class NetworkStyle;

/** Class for the splashscreen with information of the running client.
 *
 * @note this is intentionally not a QSplashScreen. Zumy initialization
 * can take a long time, and in that case a progress window that cannot be
 * moved around and minimized has turned out to be frustrating to the user.
 */
class SplashScreen : public QWidget
{
    Q_OBJECT

public:
    explicit SplashScreen(Qt::WindowFlags f, const NetworkStyle *networkStyle);
    ~SplashScreen();

protected:
    void paintEvent(QPaintEvent *event);
    void closeEvent(QCloseEvent *event);

public Q_SLOTS:
    /** Slot to call finish() method as it's not defined as slot */
    void slotFinish(QWidget *mainWin);

    /** Show message and progress */
    void showMessage(const QString &message, int alignment, const QColor &color);

private:
    /** Connect core signals to splash screen */
    void subscribeToCoreSignals();
    /** Disconnect core signals to splash screen */
    void unsubscribeFromCoreSignals();

    QPixmap pixmap;
    QString curMessage;
    QColor curColor;
    int curAlignment;
};

#endif // ZUMY_QT_SPLASHSCREEN_H