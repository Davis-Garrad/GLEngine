.PHONY: clean All

All:
	@echo "----------Building project:[ GLEngine - Release ]----------"
	@"$(MAKE)" -f  "GLEngine.mk"
clean:
	@echo "----------Cleaning project:[ GLEngine - Release ]----------"
	@"$(MAKE)" -f  "GLEngine.mk" clean
