#!/bin/sh -xe

HOOK_DIR=../../.git/hooks
cp -i pre-commit "$HOOK_DIR"
exec "$HOOK_DIR"/pre-commit
