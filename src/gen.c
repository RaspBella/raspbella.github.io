#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define ME "RaspBella"

#define OUTPUT_DIR "../docs"
#define INDEX "/index.html"

#define URL_HOME "/"
#define TEXT_HOME "home"

#define URL_ABOUT "/" ME
#define TEXT_ABOUT "about"

#define URL_CUBING "/cubing"
#define TEXT_CUBING "cubing"

#define URL_LINUX "/linux"
#define TEXT_LINUX "linux"

#define URL_MEDIA "/media"
#define TEXT_MEDIA "media"

#define URL_TRANS "/trans"
#define TEXT_TRANS "transportation"

#define URL_BLOG "/blog"
#define TEXT_BLOG "blog"

#define URL_CALENDAR "/calendar"
#define TEXT_CALENDAR "calendar"

#define ACTIVE "class=\"active\" "

#define ACTIVE_HOME ACTIVE
#define ACTIVE_ABOUT ""
#define ACTIVE_CUBING ""
#define ACTIVE_LINUX ""
#define ACTIVE_MEDIA ""
#define ACTIVE_TRANS ""
#define ACTIVE_BLOG ""
#define ACTIVE_CALENDAR ""

#define ANCHOR(INTERNAL, TEXT) "<a " INTERNAL ">" TEXT "</a>"

#define HREF(URL) "href=\"" URL "\""

#define HEADER "<ul class=\"nav\">\n" \
           "      <li>" ANCHOR(ACTIVE_HOME HREF(URL_HOME), TEXT_HOME) "</li>\n" \
           "      <li>" ANCHOR(ACTIVE_ABOUT HREF(URL_ABOUT), TEXT_ABOUT) "</li>\n" \
           "      <li>" ANCHOR(ACTIVE_CUBING HREF(URL_CUBING), TEXT_CUBING) "</li>\n" \
           "      <li>" ANCHOR(ACTIVE_LINUX HREF(URL_LINUX), TEXT_LINUX) "</li>\n" \
           "      <li>" ANCHOR(ACTIVE_MEDIA HREF(URL_MEDIA), TEXT_MEDIA) "</li>\n" \
           "      <li>" ANCHOR(ACTIVE_TRANS HREF(URL_TRANS), TEXT_TRANS) "</li>\n" \
           "      <li>" ANCHOR(ACTIVE_BLOG HREF(URL_BLOG), TEXT_BLOG) "</li>\n" \
           "      <li>" ANCHOR(ACTIVE_CALENDAR HREF(URL_CALENDAR), TEXT_CALENDAR) "</li>\n" \
           "    </ul>"

#define GITHUB_URL(USER, REPO) "https://github.com/" USER "/" REPO

#define REDIRECT(URL) "<meta http-equiv=\"Refresh\" content=\"0; " URL "\" />"

#define TEMPLATE "<!DOCTYPE html>\n"
"<html lang=\"en\">\n"
"  <head>\n"
"    <title>%s</title>\n"
"    <link rel=\"stylesheet\" href=\"/main.css\">\n"
"    <meta charset=\"UTF-8\">\n"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
"    <link rel=\"apple-touch-icon\" sizes=\"180x180\" href=\"/favicon/apple-touch-icon.png\">\n"
"    <link rel=\"icon\" type=\"image/png\" sizes=\"32x32\" href=\"/favicon/favicon-32x32.png\">\n"
"    <link rel=\"icon\" type=\"image/png\" sizes=\"16x16\" href=\"/favicon/favicon-16x16.png\">\n"
"    <link rel=\"manifest\" href=\"/favicon/site.webmanifest\">\n"
"  </head>\n"
"  <body>\n"
"    %s\n"
"  </body>\n"
"</html>"

int main(void) {
  FILE *fp = fopen(OUTPUT_DIR INDEX, "w");

  assert(fp != NULL);

  fprintf(
    fp,
    TEMPLATE,
    ME,
    HEADER "\n"
    "    <div>\n"
    "      <h1>"
    ANCHOR(
      HREF(
        GITHUB_URL(
          ME,
          "raspbella.github.io"
        )
      ),
      "source"
    )
    "</h1>\n"
    "    </div>"
  );

#undef ACTIVE_HOME
#define ACTIVE_HOME ""
#undef ACTIVE_LINUX
#define ACTIVE_LINUX ACTIVE

  fp = freopen(OUTPUT_DIR URL_LINUX INDEX, "w", fp);

  assert(fp != NULL);

  fprintf(
    fp,
    TEMPLATE,
    "linux - " ME,
    HEADER "\n"
    "    <div>\n"
    "      <h1>"
    ANCHOR(
      HREF(
        GITHUB_URL(
          ME,
          "dotfiles"
        )
      ),
      "dotfiles"
    )
    "</h1>\n"
    "    </div>"
  );

#undef ACTIVE_LINUX
#define ACTIVE_LINUX ""
#undef ACTIVE_MEDIA
#define ACTIVE_MEDIA ACTIVE

  fp = freopen(OUTPUT_DIR URL_MEDIA INDEX, "w", fp);

  assert(fp != NULL);

  fprintf(
    fp,
    TEMPLATE,
    "media - " ME,
    HEADER "\n"
    "    <div>\n"
    "      <ul class=\"nav\">\n"
    "        <li>"
    ANCHOR(
      HREF("/gifs"),
      "gifs"
    )
    "</li>\n"
    "        <li>"
    ANCHOR(
      HREF("/images"),
      "images"
    )
    "</li>\n"
    "      </ul>\n"
    "    </div>"
  );

  fp = freopen(OUTPUT_DIR "/gifs" INDEX, "w", fp);

  assert(fp != NULL);

  fprintf(
    fp,
    TEMPLATE,
    "gifs - " ME,
    HEADER "\n"
    "    <div>\n"
    "      <ul class=\"nav\">\n"
    "        <li>"
    ANCHOR(
      ACTIVE
      HREF("/gifs"),
      "gifs"
    )
    "</li>\n"
    "        <li>"
    ANCHOR(
      HREF("/images"),
      "images"
    )
    "</li>\n"
    "      </ul>\n"
    "      <br>\n"
    "      <img src=\"black-sabbath-war-pigs.gif\" alt=\""
    "Cat shaking it's head, captioned with a lyric from Black Sabbath's War Pigs: Evil minds that plot destruction"
    "\">\n"
    "      <br>\n"
    "      <img src=\"femtanyl-sped-up-cat.gif\" alt=\""
    "Cat eating watermelon sped up, captioned: average femtanyl enjoyer"
    "\">\n"
    "      <br>\n"
    "      <img src=\"hmm-hrmm.gif\" alt=\""
    "Cat thinking while a computer mouse pets it, captioned: hmmm hrmm hmm thinky thinky...."
    "\">\n"
    "      <br>\n"
    "      <img src=\"cat-eating-corn.gif\" alt=\""
    "A cat eating corn :3"
    "\">\n"
    "    </div>"
  );

  fp = freopen(OUTPUT_DIR "/images" INDEX, "w", fp);

  assert(fp != NULL);

  fprintf(
    fp,
    TEMPLATE,
    "images - " ME,
    HEADER "\n"
    "    <div>\n"
    "      <ul class=\"nav\">\n"
    "        <li>"
    ANCHOR(
      HREF("/gifs"),
      "gifs"
    )
    "</li>\n"
    "        <li>"
    ANCHOR(
      ACTIVE HREF("/images"),
      "images"
    )
    "</li>\n"
    "      </ul>\n"
    "      <br>\n"
    "      <img src=\"megasmile.webp\" alt=\"mega smile\">\n"
    "      <br>\n"
    "      <img src=\"megasmirk.webp\" alt=\"mega smirk\">\n"
    "    </div>"
  );

#undef ACTIVE_MEDIA
#define ACTIVE_MEDIA ""
#undef ACTIVE_ABOUT
#define ACTIVE_ABOUT ACTIVE

  fp = freopen(OUTPUT_DIR "/game" INDEX, "w", fp);

  assert(fp != NULL);

  fprintf(
    fp,
    TEMPLATE,
    "about gaming - " ME,
    HEADER "\n"
    "    <div>\n"
    "      <h2>Profiles</h2>\n"
    "      <p>"
    ANCHOR(
      HREF("/game/steam"),
      "steam"
    )
    "</p>\n"
    "      <p>"
    ANCHOR(
      HREF("/game/osu"),
      "osu"
    )
    "</p>\n"
    "    </div>"
  );

  fp = freopen(OUTPUT_DIR "/game/steam" INDEX, "w", fp);

  assert(fp != NULL);

  fprintf(
    fp,
    REDIRECT("https://steamcommunity.com/id/" ME)
  );

  fp = freopen(OUTPUT_DIR "/game/osu" INDEX, "w", fp);

  assert(fp != NULL);

  fprintf(
    fp,
    REDIRECT("https://osu.ppy.sh/users/" ME)
  );

  fclose(fp);
}
