#include "stdafx.h"
#include "AquaLib.h"

#include <afxinet.h>
#include <curl/curl.h>
#include <atlsafe.h>
#include <vector>

char * handle_url(char * url)
{
	CURL *curl;
    struct url_data data;

    data.size = 0;
    data.data = (char *)malloc(4096); /* reasonable size initial buffer */
    if (NULL == data.data) {
        //fprintf(stderr, "Failed to allocate memory.\n");
        return NULL;
    }
    data.data[0] = '\0';

    CURLcode res;
    struct curl_slist *headers = NULL;
    // headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    // headers = curl_slist_append(headers, "charsets: utf-8");

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"reqtype\":\"auth\",\"id\":\"8DC8B056\",\"pass\":\"849DEEE4\",\"iid\":\"12341234123412341234\"}");
        // curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            //fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return data.data;
}


size_t write_data(void * ptr, size_t size, size_t nmemb, struct url_data * data)
{
	size_t index = data->size;
    size_t n = (size * nmemb);
    char* tmp;

    data->size += (size * nmemb);

#ifdef DEBUG
    //fprintf(stderr, "data at %p size=%ld nmemb=%ld\n", ptr, size, nmemb);
#endif
    tmp = (char *)realloc(data->data, data->size + 1); /* +1 for '\0' */

    if (tmp) {
        data->data = tmp;
    } else {
        if (data->data) {
            free(data->data);
        }
        //fprintf(stderr, "Failed to allocate memory.\n");
        return 0;
    }

    memcpy((data->data + index), ptr, n);
    data->data[data->size] = '\0';

    return size * nmemb;
}

char * handle_url_fields(char * url, char * fields)
{
	CURL *curl;
    struct url_data data;

    data.size = 0;
    data.data = (char *)malloc(4096); /* reasonable size initial buffer */
    if (NULL == data.data) {
        //fprintf(stderr, "Failed to allocate memory.\n");
        return NULL;
    }
    data.data[0] = '\0';

    CURLcode res;
    struct curl_slist *headers = NULL;
    // headers = curl_slist_append(headers, "Accept: application/json");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    // headers = curl_slist_append(headers, "charsets: utf-8");

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fields);
        // curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            //fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return data.data;
}