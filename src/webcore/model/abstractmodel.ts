"use strict";

export class AbstractModel {
	public _wasm_model: any = null;

	constructor(context: any) {
		this._wasm_model = new context.module.AbstractModel();
	}

	public getProps(): any {
		return this._wasm_model.getProps();
	}

	public getPropBy(key: string): any {
		return this._wasm_model.getProps()[key];
	}

	public setProp(key, value): void {
		this._wasm_model.setProp(key, value);
	}
};
