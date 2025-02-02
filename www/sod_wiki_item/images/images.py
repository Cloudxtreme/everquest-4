import PIL
from PIL import Image, ImageDraw, ImageFont

import urllib, cStringIO

def create_spritesheet(filename, begin, end):

    text_height = 16

    sprite_width  = 40
    sprite_height = 40 + text_height

    images_per_row = 10

    spritesheet_width  = sprite_width  * images_per_row
    spritesheet_height = sprite_height * images_per_row

    spritesheet = Image.new('RGBA', (spritesheet_width, spritesheet_height), (0, 0, 0, 0))

    sprite_x = 0
    sprite_y = 0

    image_max = 1463

    draw_font = ImageFont.truetype("Minecraftia.ttf", 8)

    for index in xrange(begin, end):

        if index == image_max:
            break

        url = 'http://www.shardsofdalaya.com/fomelo/images/icons/item_' + str(index) + '.png'

        file = cStringIO.StringIO(urllib.urlopen(url).read())

        sprite = Image.open(file).convert('RGBA')

        print sprite.format, sprite.size, sprite.mode

        draw = ImageDraw.Draw(spritesheet)

        draw_x = sprite_x + 1
        draw_y = sprite_y + 1

        draw.text((draw_x + 1, draw_y + 1), str(index), font=draw_font, fill=(0,0,0))
        draw.text((draw_x - 1, draw_y - 1), str(index), font=draw_font, fill=(0,0,0))
        draw.text((draw_x + 1, draw_y - 1), str(index), font=draw_font, fill=(0,0,0))
        draw.text((draw_x - 1, draw_y + 1), str(index), font=draw_font, fill=(0,0,0))

        draw.text((draw_x + 1, draw_y),     str(index), font=draw_font, fill=(0,0,0))
        draw.text((draw_x - 1, draw_y),     str(index), font=draw_font, fill=(0,0,0))
        draw.text((draw_x,     draw_y + 1), str(index), font=draw_font, fill=(0,0,0))
        draw.text((draw_x,     draw_y - 1), str(index), font=draw_font, fill=(0,0,0))

        draw.text((draw_x, draw_y), str(index), font=draw_font, fill=(255,255,255))

        del draw

        spritesheet.paste(sprite, (sprite_x, sprite_y + text_height))

        sprite_x += sprite_width

        if sprite_x == spritesheet_width:
            sprite_x = 0
            sprite_y += sprite_height

        index = index + 1

    spritesheet.save(filename)

for index in xrange(500, 1500, 100):

    print index

    create_spritesheet('images' + str(index) + '.png', index, index + 100)