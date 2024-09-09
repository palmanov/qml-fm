/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c FileHelper -a filehelper_adaptor FileOperationsInterface.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "filehelper_adaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class FileHelper
 */

FileHelper::FileHelper(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

FileHelper::~FileHelper()
{
    // destructor
}

void FileHelper::DeleteFile(const QString &filePath)
{
    // handle method call com.example.filehelper.DeleteFile
    QMetaObject::invokeMethod(parent(), "DeleteFile", Q_ARG(QString, filePath));
}

void FileHelper::PasteFile(const QString &source, const QString &destination)
{
    // handle method call com.example.filehelper.PasteFile
    QMetaObject::invokeMethod(parent(), "PasteFile", Q_ARG(QString, source), Q_ARG(QString, destination));
}

