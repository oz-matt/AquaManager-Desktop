#pragma once

struct url_data {
    size_t size;
    char* data;
};

char * handle_url(char * url);
size_t write_data(void * ptr, size_t size, size_t nmemb, struct url_data * data);
char * handle_url_fields(char * url, char * fields);