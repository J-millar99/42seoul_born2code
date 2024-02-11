FROM debian:bookworm

# Install required packages
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    nginx \
    openssl \
    && rm -rf /var/lib/apt/lists/*

# Copy Nginx configuration file
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Command to run on container startup
CMD ["nginx", "-g", "daemon off;"]