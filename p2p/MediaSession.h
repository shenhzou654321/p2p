#ifndef MEDIA_SESSION_H
#define MEDIA_SESSION_H

#include "RtpSink.h"

class MediaSession
{
public:
	MediaSession(asio::io_service& io_service);
	virtual ~MediaSession();

	bool Open();
	void Close();

	void StartPlay();
	void StopPlay();

	int SendFrame(uint8_t* data, uint32_t size, uint8_t type, uint32_t timestamp);

	bool IsPlaying() const
	{ return is_playing_; }

private:
	asio::io_service& io_service_;
	std::unique_ptr<RtpSink> rtp_sink_;

	bool is_playing_;
};

#endif