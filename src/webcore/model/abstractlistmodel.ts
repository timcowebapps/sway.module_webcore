"use strict";

export class AbstractListModel {
	public _wasm_listmodel: any = null;

	constructor(context: any) {
		this._wasm_listmodel = new context.module.AbstractListModel();
	}

	public getItemAt(idx: number): any {
		return this._wasm_listmodel.getItems()[idx];
	}

	public getItems(): any {
		return this._wasm_listmodel.getItems();
	}

	public setItem(idx, value): void {
		this._wasm_listmodel.setItem(idx, value._wasm_model);
	}
};
