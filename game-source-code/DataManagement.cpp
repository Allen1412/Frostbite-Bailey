#include "DataManagement.h"


void DataManagement::texture_loader(const Texture_& texture_name, const string& path)
{
    Texture tex;
//
   if( tex.loadFromFile(path))
    {

        if( _textures.size( ) == 0)
          _textures.push_back(tex);
  else _textures.at(static_cast <int> (texture_name)) = tex;

}
    else throw TextureNotFound{ };

  //  if(tex.loadFromFile(path))
      //  std::cout  <<  texture_name ;
   //     _textures.at(texture_name) = tex;
}


void DataManagement::font_loader(const Font_& font_name,const  string& path)
{

    Font fnt;

    if( fnt.loadFromFile(path))
    {
        if (_fonts.size() ==0)
            _fonts.push_back(fnt);
            else _fonts.at(static_cast<int> (font_name)) = fnt;
        }

        else
            throw FontNotFound{ };
     //   game_fonts.at(font_name) = fnt;
}


Texture& DataManagement::get_texture(const Texture_& texture_name)
{
    return  _textures.at(static_cast<int> (texture_name));
   //return _textures.at(texture_name);
}


Font& DataManagement::get_font(const Font_& font_name)
{
     return _fonts.at(static_cast<int> (font_name));
    //return _fonts.at(font_name);
}
