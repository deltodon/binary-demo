.PHONY: all build-cython
all: help

DOCKER_IMG="binary-demo"

.venv:
	@echo "Installing project dependencies.."
	@uv sync

profile:
	@echo "Setting conan profile.."
	@uv run conan profile detect --force

create:
	@echo "Creating and testing C++ package.."
	@uv run conan create .

build:
	@echo "Building C++ package locally.."
	@uv run conan install . --build=missing
	@uv run conan build .

jupyter:
	@echo "Running JupyterLab.."
	@if [ -f .env ]; then \
		uv run --env-file=.env jupyter lab; \
	else \
		uv run jupyter lab; \
	fi

rebuild: clean-build clean-venv
	@uv sync --reinstall

test:
	@echo "Running unit tests.."
	@uv run pytest

clean-venv:
	@echo "Removing .venv directory.."
	@rm -rf .venv

clean-build:
	@echo "Removing build directory.."
	@rm -rf build

clean-conan:
	@echo "Removing .conan2 cache directory.."
	@rm -rf .conan2

clean-docker:
	@echo "Removing Docker image.."
	@rm -rf .venv
	@if docker image inspect ${DOCKER_IMG}:latest >/dev/null 2>&1; then \
		echo "Removing Docker image ${DOCKER_IMG}"; \
		docker image rm ${DOCKER_IMG}:latest; \
	else \
		echo "Docker image ${DOCKER_IMG} not found"; \
	fi

clean-python:
	@echo "Removing Python build directories.."
	@rm -rf `find -type d -name __pycache__`
	@rm -rf `find -type d -name .pytest_cache`
	@rm -rf `find -type d -name .ipynb_checkpoints`

clean-all: clean-docker clean-build clean-conan clean-venv clean-python
	@echo "All clean operations completed."


help:
	@echo "Available make targets:"
	@echo " make help         - Print help"
	@echo " make .venv        - Install project dependencies"
	@echo " make profile      - Set conan profile"
	@echo " make build        - Build C++ package locally"
	@echo " make jupyter      - Run JupyterLab"
	@echo " make test         - Run unit tests"
	@echo " make clean-docker - Remove Docker image"
	@echo " make clean-venv   - Remove .venv"
	@echo " make clean-build  - Remove build"
	@echo " make clean-conan  - Remove .conan2 cache"
	@echo " make clean-python - Remove Python build directories"
	@echo " make clean-all    - Remove all binaries"
	@echo ""
