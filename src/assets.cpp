#include "assets.h"

#include "texture.h"

#include <raylib.h>

namespace MR
{

Font Assets::m_fontSnow;
Font Assets::m_fontMedium;
Font Assets::m_fontRegular;

std::map<int, MR::Texture *> Assets::m_texturesMap;
int Assets::m_textureIndex{0};

Texture2D Assets::m_mouseTexture;
Texture2D Assets::m_buttonTexture;

Texture2D Assets::m_snowTexture;

Texture2D Assets::m_playerTexture;

Texture2D Assets::m_propSawTexture;
Texture2D Assets::m_propSawHolderTexture;
Texture2D Assets::m_propGhandilTexture;

Texture2D Assets::m_propCoinTexture;

Texture2D Assets::m_bgSkyTexture;
Texture2D Assets::m_bgCloudTexture;
Texture2D Assets::m_bgTreeTexture;

Texture2D Assets::m_envTileTexture;

std::map<int, MR::Sound *> Assets::m_soundsMap;
std::map<int, MR::Music *> Assets::m_musicsMap;

void Assets::load()
{
    m_fontSnow = LoadFontEx("../assets/fonts/SnowtopCaps.ttf", 96, 0, 0);
    GenTextureMipmaps(&m_fontSnow.texture);
    SetTextureFilter(m_fontSnow.texture, TEXTURE_FILTER_BILINEAR);

    m_fontMedium = LoadFontEx("../assets/fonts/Vazir-Medium.ttf", 96, 0, 0);
    GenTextureMipmaps(&m_fontMedium.texture);
    SetTextureFilter(m_fontMedium.texture, TEXTURE_FILTER_BILINEAR);

    m_fontRegular = LoadFontEx("../assets/fonts/Vazir-Regular.ttf", 96, 0, 0);
    GenTextureMipmaps(&m_fontRegular.texture);
    SetTextureFilter(m_fontRegular.texture, TEXTURE_FILTER_BILINEAR);

    // Texture loading section
    m_mouseTexture = LoadTexture("../assets/textures/mouse.png");
    for (int x = 0; x < 2; x += 1)
    {
        m_textureIndex += 1;
        m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, x * 16, 0, 16, 16, &m_mouseTexture)));
    }
//    1: cursor 2: marker

    m_buttonTexture = LoadTexture("../assets/textures/button.png");
    for (int y = 0; y < 2; y += 1)
    {
        m_textureIndex += 1;
        m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, 0, y * 48, 120, 48, &m_buttonTexture)));
    }
//    3: button

    m_snowTexture = LoadTexture("../assets/textures/snow.png");
    for (int y = 0; y < 2; y += 1)
    {
        for (int x = 0; x < 2; x += 1)
        {
            m_textureIndex += 1;
            m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, x * 256, y * 256, 256, 256, &m_snowTexture)));
        }
    }
//    4: 5: 6: 7: snow

    m_playerTexture = LoadTexture("../assets/textures/player.png");
    for (int x = 0; x < 5; x += 1)
    {
        m_textureIndex += 1;
        m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, x * 180, 0, 180, 300, &m_playerTexture)));
    }
//    8: 9: 10: 11: 12: player

    m_propSawTexture = LoadTexture("../assets/textures/saw.png");
    m_textureIndex += 1;
    m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, 0, 0, 256, 256, &m_propSawTexture)));
//    13: prop saw

    m_propSawHolderTexture = LoadTexture("../assets/textures/paye.png");
    m_textureIndex += 1;
    m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, 0, 0, 256, 256, &m_propSawHolderTexture)));
//    14: prop PROP_SAW_HOLDER

    m_propGhandilTexture = LoadTexture("../assets/textures/ghandil.png");
    m_textureIndex += 1;
    m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, 0, 0, 55, 265, &m_propGhandilTexture)));
//    15: prop PROP_GHANDIL

    m_propCoinTexture = LoadTexture("../assets/textures/coin.png");
    m_textureIndex += 1;
    m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, 0, 0, 64, 64, &m_propCoinTexture)));
//    16: prop coin

    m_bgSkyTexture= LoadTexture("../assets/textures/background.png");
    m_textureIndex += 1;
    m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, 0, 0, 800, 600, &m_bgSkyTexture)));
//    17: env sky

    m_bgCloudTexture= LoadTexture("../assets/textures/clouds.png");
    for (int x = 0; x < 2; x += 1)
    {
        m_textureIndex += 1;
        m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, 0, 0, 128, 128, &m_bgCloudTexture)));
    }
//    18: 19 env Clouds

    m_bgTreeTexture= LoadTexture("../assets/textures/tree.png");
    m_textureIndex += 1;
    m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, 0, 0, 256, 256, &m_bgTreeTexture)));
//    20: env tile grass

    m_envTileTexture= LoadTexture("../assets/textures/tiles.png");
    for (int x = 0; x < 3; x += 1)
    {
        m_textureIndex += 1;
        m_texturesMap.insert(std::make_pair(m_textureIndex, new MR::Texture(m_textureIndex, x * 65, 0, 65, 65, &m_envTileTexture)));
    }
//    21, 22, 23: env tile grass

    // load sound files
    m_soundsMap.insert(std::make_pair(1, new MR::Sound(1, "../assets/sounds/jump.wav")));
    // JUMP 1

    m_musicsMap.insert(std::make_pair(1, new MR::Music(1, "../assets/sounds/music.mp3")));
    // MUSIC 1
}

void Assets::unload()
{
    for (auto &snd : m_soundsMap)
    {
        delete snd.second;
    }
    m_soundsMap.clear();

    for (auto &mus : m_musicsMap)
    {
        delete mus.second;
    }
    m_musicsMap.clear();

    UnloadFont(m_fontSnow);
    UnloadFont(m_fontMedium);
    UnloadFont(m_fontRegular);

    for (auto &tex : m_texturesMap)
    {
        delete tex.second;
    }
    m_texturesMap.clear();

    UnloadTexture(m_mouseTexture);
    UnloadTexture(m_buttonTexture);

    UnloadTexture(m_snowTexture);

    UnloadTexture(m_playerTexture);

    UnloadTexture(m_propSawTexture);
    UnloadTexture(m_propSawHolderTexture);
    UnloadTexture(m_propGhandilTexture);

    UnloadTexture(m_propCoinTexture);

    UnloadTexture(m_bgSkyTexture);
    UnloadTexture(m_bgCloudTexture);
    UnloadTexture(m_bgTreeTexture);

    UnloadTexture(m_envTileTexture);
}

const Font &Assets::fontSnow()
{
    return m_fontSnow;
}

const Font &Assets::fontMedium()
{
    return m_fontMedium;
}

const Font &Assets::fontRegular()
{
    return m_fontRegular;
}

MR::Texture *Assets::getTextureByID(int id)
{
//    if (!m_texturesMap.contains(id))
//    {
//        return nullptr;
//    }

    return m_texturesMap.at(id);
}

Sound *Assets::getSoundByID(int id)
{
//    if (!m_soundsMap.contains(id))
//    {
//        return nullptr;
//    }

    return m_soundsMap.at(id);
}

Music *Assets::getMusicByID(int id)
{
//    if (!m_musicsMap.contains(id))
//    {
//        return nullptr;
//    }

    return m_musicsMap.at(id);
}

}
