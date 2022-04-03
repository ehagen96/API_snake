#pragma once

class SDLInit {
public:
    SDLInit(unsigned flags);
	~SDLInit() noexcept;
    SDLInit(const SDLInit &other) = delete;
    SDLInit(SDLInit &&other) noexcept = delete;
    SDLInit &operator=(const SDLInit &rv) = delete;
    SDLInit &operator=(SDLInit &&rv) noexcept = delete;
};
