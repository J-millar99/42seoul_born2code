FROM debian:bookworm

# Install Nginx
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    nginx \
    && rm -rf /var/lib/apt/lists/*

# Copy HTML files
COPY html /var/www/html

# Copy Nginx configuration file
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Command to run on container startup
CMD ["nginx", "-g", "daemon off;"]
