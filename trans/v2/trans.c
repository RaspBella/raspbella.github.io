#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "json.h"
#include "trans.h"
#include "bestline.h"
#include "usage.h"

int jsonparse(void *scanner, Json **result);
int jsonlex_init(void **scanner);
int jsonlex_destroy(void *scanner);
void jsonset_in(FILE *fp, void *scanner);
int transparse(void *scanner, Json *data);
int translex_init(void **scanner);
int translex_destroy(void *scanner);
void transset_in(FILE *fp, void *scanner);

const char data_filename[] = "data.json";

Json *data = NULL;
Map *vars = NULL;

char *buffer = NULL;

FILE *parse_buffer = NULL;
void *scanner = NULL;

void clean_up(void) {
  FILE *fp = fopen(data_filename, "w");

  fprint_json(data, fp);

  fclose(fp);

  free_json(data);
  free_map(vars, free, (void (*)(void*))free_json);

  if (buffer) free(buffer);
}

void init(void) {
  FILE *fp = fopen(data_filename, "r");

  if (fp) {
    void *scanner;

    jsonlex_init(&scanner);
    jsonset_in(fp, scanner);

    if (jsonparse(scanner, &data)) {
      fprintf(stderr, "Invalid json\n");
    }

    jsonlex_destroy(scanner);

    fclose(fp);
  }

  if (!data) {
    data = new_json(JsonObject, NULL);

    map_set(data->data.object, strdup("version"), new_json(JsonNumber, new_number(TRANS_VERSION)));
  }

  vars = new_map(0, NULL, NULL);

  atexit(clean_up);
}

void main_exit(int code) {
  translex_destroy(scanner);

  fclose(parse_buffer);

  exit(code);
}

int main(int argc, char **argv) {
  if (argc == 1) {
    init();

    while ((buffer = bestlineWithHistory("> ", "trans"))) {
      parse_buffer = fmemopen(buffer, strlen(buffer) + 1, "r");

      translex_init(&scanner);
      transset_in(parse_buffer, scanner);

      transparse(scanner, data);

      translex_destroy(scanner);

      fclose(parse_buffer);

      free(buffer);
    }

    exit(EXIT_SUCCESS);
  }

  else if (argc == 3) {
    if (argv[1][0] == '-') {
      if (argv[1][1] == 'h' && argv[1][2] == 0) {
        usage(stdout, NULL);

        exit(EXIT_SUCCESS);
      }

      else if (argv[1][1] == 'c' && argv[1][2] == 0) {
        init();

        parse_buffer = fmemopen(argv[2], strlen(argv[2]) + 1, "r");

        translex_init(&scanner);
        transset_in(parse_buffer, scanner);

        transparse(scanner, data);

        translex_destroy(scanner);

        fclose(parse_buffer);

        exit(EXIT_SUCCESS);
      }

      else if (argv[1][1] == 'f' && argv[1][2] == 0) {
        init();

        parse_buffer = fopen(argv[2], "r");

        translex_init(&scanner);
        transset_in(parse_buffer, scanner);

        transparse(scanner, data);

        translex_destroy(scanner);

        fclose(parse_buffer);
        
        exit(EXIT_SUCCESS);
      }
    }
  }

  usage(stderr, NULL);
  exit(EXIT_FAILURE);
}
