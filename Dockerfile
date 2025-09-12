# Base Image
FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    curl \
    pkg-config \
    libpqxx-dev \
    libyaml-cpp-dev \
    postgresql-client \
    && rm -rf /var/lib/apt/lists/*

# Working Dir:
WORKDIR /app

EXPOSE 8080

HEALTHCHECK --interval=30s --timeout=3s --start-period=5s --retries=3 CMD curl -f http://localhost:8080/health || exit 1

CMD ["/bin/bash"]