.PHONY: clean All

All:
	@echo "----------Building project:[ MSP - Debug ]----------"
	@"$(MAKE)" -f  "MSP.mk"
clean:
	@echo "----------Cleaning project:[ MSP - Debug ]----------"
	@"$(MAKE)" -f  "MSP.mk" clean
