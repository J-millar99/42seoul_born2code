#!/bin/bash
mkdir -p /etc/nginx/certs/

openssl req -newkey rsa:4096 -x509 -sha256 -nodes \
    -out $API_CRT \
    -keyout $API_KEY \
    -subj "$API_INFO"

chmod 600 $API_KEY
chmod 644 $API_CRT

nginx -g "daemon off;"