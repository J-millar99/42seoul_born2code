FROM debian:bookworm

# Install Redis
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    redis-server \
    && rm -rf /var/lib/apt/lists/*

# Copy Redis configuration
COPY conf/redis.conf /etc/redis/redis.conf

# Command to run on container startup
CMD ["redis-server", "/etc/redis/redis.conf"]
