#include "APIManager.h"
#include <QEventLoop>

APIManager::APIManager(QString ip, int port, QObject* parent)
	: QObject(parent), ip(ip), port(port)
{
	accessManager = new QNetworkAccessManager(this);
}

User* APIManager::loadUser(int id)
{
    QNetworkRequest request(QUrl(QString("http://%1:%2/getUser/%3").arg(ip).arg(port).arg(id)));
    QNetworkReply* reply = accessManager->get(request);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (!jsonDoc.isObject()) {
            lastAPIError = "LOAD-USER_INVALID-RESPONSE";
            errorDetails = "Response is not a valid JSON object";
            reply->deleteLater();
            return nullptr;
        }

        QJsonObject obj = jsonDoc.object();
        User* user = new User(
            obj["prenom"].toString(),
            obj["nom"].toString(),
            obj["nickname"].toString(),
            obj["rfid"].toString(),
            obj["password"].toString(),
            obj["isAdmin"].toBool(),
            obj["quota"].toInt(),
            obj["id"].toInt()
        );
        lastAPIError = "";
        errorDetails = "";
        qDebug() << "Utilisateur chargé : " << user->getNickname();
        reply->deleteLater();
        return user;
    }
    else {
        lastAPIError = "LOAD-USER_REQUEST-FAILED";
        errorDetails = reply->errorString();
        qDebug() << "Erreur lors de la récupération de l'utilisateur : " << errorDetails;
        reply->deleteLater();
        return nullptr;
    }
}

QList<User*> APIManager::loadUsers()
{
    QNetworkRequest request(QUrl(QString("http://%1:%2/getUsers").arg(ip).arg(port)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply* reply = accessManager->get(request);

    // QEventLoop pour looper jusqu'à ce que la réponse soit reçue
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    QList<User*> users;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (jsonDoc.isArray()) {
            QJsonArray jsonArray = jsonDoc.array();
            for (int i = 0; i < jsonArray.size(); i++) {
                if (jsonArray[i].isObject()) {
                    QJsonObject userObj = jsonArray[i].toObject();
                    User* user = new User(
                        userObj["prenom"].toString(),
                        userObj["nom"].toString(),
                        userObj["nickname"].toString(),
                        userObj["rfid"].toString(),
                        userObj["password"].toString(),
                        userObj["isAdmin"].toBool(),
                        userObj["quota"].toInt(),
                        userObj["id"].toInt()
                    );
                    users.append(user);
                }
            }
        }
        lastAPIError = "";
        errorDetails = "";
    }
    else {
        lastAPIError = "LOAD-USERS_REQUEST-FAILED";
        errorDetails = reply->errorString();
        qDebug() << "Erreur lors de la récupération des utilisateurs : " << reply->errorString();
    }
    reply->deleteLater();
    return users;
}

bool APIManager::saveUser(User* user)
{
    if (!user) {
        lastAPIError = "SAVE-USER_NO-USER-ARG";
        errorDetails = "No user argument";
        qDebug() << "Utilisateur invalide, annulation de l'enregistrement.";
        return false;
    }

    QNetworkRequest request(QUrl(QString("http://%1:%2/addUser").arg(ip).arg(port)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonObject userObj;
    userObj["prenom"] = user->getPrenom();
    userObj["nom"] = user->getNom();
    userObj["nickname"] = user->getNickname();
    userObj["rfid"] = user->getRFID();
    userObj["password"] = user->getPassword();
    userObj["id"] = user->getId();

    QJsonDocument jsonDoc(userObj);
    QByteArray jsonData = jsonDoc.toJson();

    QNetworkReply* reply = accessManager->post(request, jsonData);

    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    bool success = false;
    if (reply->error() == QNetworkReply::NoError) {
        success = true;
        lastAPIError = "";
        errorDetails = "";
    }
    else
    {
        lastAPIError = "SAVE-USER_SAVE-FAILED";
        errorDetails = reply->errorString();
    }
    reply->deleteLater();
    return success;
}

QString APIManager::GetLastAPIError()
{
    return lastAPIError;
}

QString APIManager::GetErrorDetails()
{
    return errorDetails;
}
