FROM ghcr.io/ledgerhq/ledger-app-builder/ledger-app-builder-lite:latest AS LITE_BUILDER

# Base image with clang toolchain
FROM gcr.io/oss-fuzz-base/base-builder:v1

# Copy the project's source code.
COPY . $SRC/LedgerHQ-app-plugin-stakekit
COPY --from=LITE_BUILDER /opt/nanox-secure-sdk $SRC/LedgerHQ-app-plugin-stakekit/BOLOS_SDK

# Working directory for build.sh
WORKDIR $SRC/LedgerHQ-app-plugin-stakekit

# Copy build.sh into $SRC dir.
COPY ./.clusterfuzzlite/build.sh $SRC/
