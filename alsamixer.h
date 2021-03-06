#ifndef ALSAMIXER_H
#define ALSAMIXER_H

#include <QtCore/QLoggingCategory>
#include <QObject>

Q_DECLARE_LOGGING_CATEGORY(ALSAMixerLog)

struct ALSAMixerPrivate;

class ALSAMixer : public QObject
{
    Q_OBJECT
public:
    explicit ALSAMixer(const QString &deviceName = "default", QObject *parent = 0);
    ~ALSAMixer();

    float getMasterVolume();

public slots:
    void setMasterVolume(float volume);

private:
    ALSAMixerPrivate *d_ptr;
    Q_DECLARE_PRIVATE(ALSAMixer);
};

#endif // ALSAMIXER_H
